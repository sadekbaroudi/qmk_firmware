#!/bin/bash

# error handling
if ! command -v jq &> /dev/null
then
    echo "jq is a dependency, and could not be found, see https://stedolan.github.io/jq for installation details"
    exit
fi

Help()
{
	echo "Usage: $0 -k <keyboard> -m <keymap> -c <convert_to controller> -r -h"
	echo ""
    echo "  -l list valid keyboards (optional, overrides all other options)"
	echo "  -k keyboard directory (optional, default is all fingerpunch keyboards)"
	echo "  -m keymap (optional, defaults to the 'default' keymap)"
	echo "  -c add CONVERT_TO parameter for a controller (eg -c stemcell)"
    echo "  -i (interactive mode, take feature selection user input to generate build command)"
	echo "  -r (run the build command(s), defaults to outputting the build string)"
	echo "  -e (add environment variables, only used in interactive mode, e.g. RGB_MATRIX_REACTIVE_LAYERS=yes or -e \"RGB_LED_RING=yes RGBLIGHT_SNAKE_LAYERS=yes\")"
	echo "  -d run using util/docker_build.sh"
	echo "  -h (show this dialog)"
	echo ""
	echo "Examples: "
	echo "--------"
	echo "fp_build.sh -i -k \"rockon/v2\" -m sadekbaroudi -r"
	echo "fp_build.sh -i -m sadekbaroudi"
	echo "fp_build.sh -k \"barobord\""
}

get_valid_keyboards() {
	valid_keyboards=""

	directories=$(find ${1}/* -maxdepth 0 -type d)
	echo "${directories}" | while read line; do
		# first we do a basic test to see if fp_build.json is in the keyboard root directory
		if [[ -e "${line}/fp_build.json" ]]; then
		    echo -n "${line} "
		fi

		# check for all the supported versions of the keyboard in the keyboard root directory
		for i in {0..9}
		do
			if [[ -e "${line}/v${i}/fp_build.json" ]]; then
			    echo -n "${line}/v${i} "
			fi

			# handle format with subversions, like v3_1
			for j in {0..9}
			do
				if [[ -e "${line}/v${i}_${j}/fp_build.json" ]]; then
					echo -n "${line}/v${i}_${j} "
				fi
			done

			# special case for pinkies out v2 extended
			if [[ -e "${line}/v${i}_ext/fp_build.json" ]]; then
			    echo -n "${line}/v${i}_ext "
			fi
		done

		# special case for tenbit
		for i in {4..5}
		do
			if [[ -e "${line}/${i}x12/fp_build.json" ]]; then
			    echo -n "${line}/${i}x12 "
			fi
		done

		# special case for vulpes minora byomcu
		if [[ -e "${line}/byomcu/fp_build.json" ]]; then
			echo -n "${line}/byomcu "
		fi

		# special case for vulpes minora rp2040zero
		if [[ -e "${line}/rp2040zero" ]]; then
			echo -n "${line}/rp2040zero "
		fi

		# special case for vulpes minora xivik
		if [[ -e "${line}/xivik" ]]; then
			echo -n "${line}/xivik "
		fi

		# if we have a second parameter, then we don't want to recurse again
		if [ "$#" -lt 2 ]; then
			# now check for byomcu version, repeating the logic above
			if [[ -e "${line}/byomcu" ]]; then
				echo $(get_valid_keyboards "${line}/byomcu" "false")
			fi

			# now check for atmega version
			if [[ -e "${line}/atmega" ]]; then
				echo $(get_valid_keyboards "${line}/atmega" "false")
			fi

			# now check for rp2040 version
			if [[ -e "${line}/rp" ]]; then
				echo $(get_valid_keyboards "${line}/rp" "false")
			fi

			# now check for stm version
			if [[ -e "${line}/stm" ]]; then
				echo $(get_valid_keyboards "${line}/stm" "false")
			fi
		fi
	done
}

build_keyboard_user_input() {
	local build_json="${1}/fp_build.json"
	local keyboard_base_dir="${1}"
	local keyboard_name="${1#${2}/}"
	local run_build="${4}"
	local build_executor="${7}"

	local build_string="${build_executor} ${keyboard_base_dir#keyboards\/}:${3}"
	echo "${build_string}"
	# get the total number of paramters
	top_level_element_count=$(cat "${build_json}" | jq 'length')
    # loop through each parameter
	for ((param_iter = 0 ; param_iter < top_level_element_count ; param_iter++)); do
        # get the parameter type to decide how to handle it
		param_type=$(cat "${build_json}" | jq -r ".[${param_iter}].type")

        # get the string to present to the user for their input
		user_input_string=$(cat "${build_json}" | jq -r ".[${param_iter}].user_input")

        # if it's a "one-of"... in other words, pick an option from a list
		if [[ "${param_type}" == "one-of" ]]; then
			options_count=$(cat "${build_json}" | jq ".[${param_iter}].names | length")
			user_input_string+=" (0-${options_count}): "

			echo -n "${user_input_string}"
			read user_choice
			while [[ $user_choice -lt 0 || $user_choice -gt $options_count ]]; do
				echo "Invalid choice: ${user_choice}"
				echo -n "${user_input_string}"
				read user_choice
			done

			# start at 1, because 0 should always be "none"
			param_names_counter=1
			param_names=$(cat "${build_json}" | jq -r ".[${param_iter}].names | @sh" | tr -d \')
			for param_name in $param_names; do
			    if [[ $param_names_counter -eq $user_choice ]]; then
			    	build_string+=" ${param_name}=yes"
			    fi
			    ((param_names_counter+=1))
			done
        # if it's a single value choice for a parmeter, or "yes or no" question
		elif [[ "${param_type}" == "single" ]]; then
			user_input_string+=" (yes/no): "

			echo -n "${user_input_string}"
			read user_choice

			while [[ $user_choice != "yes" && $user_choice != "no" && $user_choice != "y" && $user_choice != "n" ]]; do
				echo "Invalid choice: ${user_choice}"
				echo -n "${user_input_string}"
				read user_choice
			done

            if [[ "${user_choice}" == "y" ]]; then
                user_choice="yes"
            fi
            if [[ "${user_choice}" == "n" ]]; then
                user_choice="no"
            fi

			param_name=$(cat "${build_json}" | jq -r ".[${param_iter}].name")
			build_string+=" ${param_name}=${user_choice}"
        elif [[ "${param_type}" == "convert-to" ]]; then
            # Do nothing, we can skip this for interactive mode
			param_name=$(cat "${build_json}" | jq -r ".[${param_iter}].name")
		else
			echo "invalid type in json file: ${param_type}"
			exit
		fi
	done

	if [[ -n "${5}" && "${5}" != "no" ]]; then
		build_string+=" CONVERT_TO=${5}"
	fi

	if [[ -n "${6}" && "${6}" != "no" ]]; then
		build_string+=" ${6}"
	fi

	process_build_string "${build_string}" "${run_build}"
}


build_keyboard_all_combinations() {
	local build_json="${1}/fp_build.json"
	local keyboard_base_dir="${1}"
	local keyboard_name="${1#${2}/}"
	local run_build="${4}"
	local build_executor="${7}"

	local build_string_base="${build_executor} ${keyboard_base_dir#keyboards\/}:${3}"

	if [[ -n "${5}" && "${5}" != "no" ]]; then
		build_string_base+=" CONVERT_TO=${5}"
	fi

	make_build_string_recursive "${build_json}" "${run_build}" 0 "${build_string_base}"
}

# make_build_string_recursive "${build_json}" "${run_build}" "${param_number}" "${build_string_base}"
make_build_string_recursive() {
    local build_json="${1}"
	local run_build="${2}"
    local param_number=$3
    local build_string_base="${4}"
	local top_level_element_count=$(cat "${build_json}" | jq 'length')

	if [[ $((param_number)) -ge $((top_level_element_count)) ]]; then
		process_build_string "${build_string_base}" "${run_build}"
		return;
	fi

    local param_type=$(cat "${build_json}" | jq -r ".[${param_number}].type")
	local next_param_number=$((param_number + 1))

    # if it's a "one-of"... in other words, pick an option from a list
    if [[ "${param_type}" == "one-of" ]]; then
		local param_names=$(cat "${build_json}" | jq -r ".[${param_number}].names | @sh" | tr -d \')
		for param_name in $param_names; do
			make_build_string_recursive "${build_json}" "${run_build}" $next_param_number "${build_string_base} ${param_name}=yes"
		done
    # if it's a single value choice for a parmeter, or "yes or no" question
    elif [[ "${param_type}" == "single" ]]; then
		local param_name=$(cat "${build_json}" | jq -r ".[${param_number}].name")
		make_build_string_recursive "${build_json}" "${run_build}" $next_param_number "${build_string_base} ${param_name}=yes"
		make_build_string_recursive "${build_json}" "${run_build}" $next_param_number "${build_string_base} ${param_name}=no"
    elif [[ "${param_type}" == "convert-to" ]]; then
		local param_name=$(cat "${build_json}" | jq -r ".[${param_number}].name")
        make_build_string_recursive "${build_json}" "${run_build}" $next_param_number "${build_string_base} CONVERT_TO=${param_name}"
    else
        echo "invalid type in json file: ${param_type}"
        exit
    fi
}

# rename_file_from_build_string $build_string $target_filename_suffix
rename_file_from_build_string() {
    tokens=( $1 )

	target_filename_suffix=""
	if [[ ! -z "${2}" ]]; then
		target_filename_suffix="_${2}"
	fi

    # Calculate the qmk build filename prefix to move it
    token_file_prefix="${tokens[1]//\//_}"
    token_file_prefix="${token_file_prefix//:/_}"

    # Start the new filename, which will be appended to below
    target_filename="${token_file_prefix}"

    # check if token_i>1
    # check if first paramter is CONVERT_TO, then grab other side of = (stemcell for example)
    # otherwise grab first parameter (RGBLIGHT_ENABLE for example)
    # rename file accordingly
    token_i=0
    for token in "${tokens[@]}"
    do
        if [[ $token_i -gt 1 ]]; then
            config_param="${token%%=*}"
            config_value="${token#*=}"
            if [[ "${config_param}" == "CONVERT_TO" ]]; then
                token_file_prefix+="_${config_value}"
                target_filename+="_${config_value}"
            else
                # Make sure that the value is yes (it's enabled), otherwise we shouldn't include in the filename
                if [[ "${config_value}" == "yes" ]]; then
                    # ,, converts to lowercase
                    target_filename+="_${config_param,,}"
                    # remove _enable suffix as it's implied
                    target_filename=${target_filename%"_enable"}
                fi
            fi
        fi
        token_i+=1
    done

    echo "${0}: filename token is ${token_file_prefix}"
    echo "${0}: target filename is ${target_filename}"

    hex_source_file="${token_file_prefix}.hex"
    uf2_source_file="${token_file_prefix}.uf2"
    hex_target_file="${target_filename}${target_filename_suffix}.hex"
    uf2_target_file="${target_filename}${target_filename_suffix}.uf2"

    if test -f "${hex_source_file}"; then
        echo "${0}: Renaming file '${hex_source_file}' to '${hex_target_file}'"
		if [ "${hex_source_file}" = "${hex_target_file}" ]; then
			echo "${0}: Skipping rename, since the file is already named appropriately"
		else
        	mv "${hex_source_file}" "${hex_target_file}"
		fi
    else
        echo "${0}: Could not find hex source file ${hex_source_file} to rename."
    fi

    if test -f "${uf2_source_file}"; then
        echo "${0}: Renaming file '${uf2_source_file}' to '${uf2_target_file}'"
		if [ "${uf2_source_file}" = "${uf2_target_file}" ]; then
			echo "${0}: Skipping rename, since the file is already named appropriately"
		else
        	mv "${uf2_source_file}" "${uf2_target_file}"
		fi
    else
        echo "${0}: Could not find uf2 source file ${uf2_source_file} to rename."
    fi
}

# process_build_string $build_string $run_build
process_build_string() {
	build_string="$1"
	run_build="$2"
	append_to_filename=""

	echo "${build_string}"

	if [[ "${run_build}" == "yes" ]]; then
		echo "fp_build.sh: Running QMK Build...."
		echo ""
		build_run_output=`${build_string}`
        build_run_status=$?
		echo "output: ${build_run_output}"
		echo "exit status: ${build_run_status}"
        if [[ $build_run_status -ne 0 ]]; then
			# if the firmware is too large, we proceed, but append to filename, otherwise we error out
			if [[ "${build_run_output}" == *"The firmware is too large"* ]]; then
				append_to_filename="FIRMWARE_SIZE_CHECK_FAILED"
			else
				echo "${0} build run failed with status ${build_run_status}"
				exit $build_run_status
			fi
        fi

        rename_file_from_build_string "${build_string}" "${append_to_filename}"
	fi
}

Keyboard=""
Keymap="default"
RunBuild="no"
ConvertTo="no"
Interactive="no"
ListKeyboards="no"
EnvVariables="no"
UseDocker="make" # defaults to make, so it doesn't use docker by default
while getopts "k:m:c:e:rhild" option; do
    case $option in
        l) ListKeyboards="yes";;
        k) Keyboard=${OPTARG};;
        m) Keymap=${OPTARG};;
        c) ConvertTo=${OPTARG};;
        i) Interactive="yes";;
        r) RunBuild="yes";;
        e) EnvVariables="${OPTARG}";;
        d) UseDocker="util/docker_build.sh";;
        h) Help
           exit;;
    esac
done

#### code starts here

# set up variables
FP_KB_DIR="keyboards/fingerpunch"
FP_KB=("${Keyboard}")
if [[ -z "${Keyboard}" || "${ListKeyboards}" == "yes" ]]; then
	FP_KB=$(get_valid_keyboards "${FP_KB_DIR}")
else
	FP_KB=("${FP_KB_DIR}/${FP_KB}")
	if [[ ! -e "${FP_KB}" ]]; then
		echo "${FP_KB} is not a valid file, can't build"
		exit
	fi
fi;

if [[ "${ListKeyboards}" == "yes" ]]; then
    # remove last space from FP_KB and convert spaces to newlines
    echo "${FP_KB%?}" | tr " " "\n"
else
    for filename in $FP_KB; do
        if [[ "${Interactive}" == "yes" ]]; then
            echo "Running for ${filename}"
            build_keyboard_user_input "${filename}" "${FP_KB_DIR}" "${Keymap}" "${RunBuild}" "${ConvertTo}" "${EnvVariables}" "${UseDocker}"
        else
            build_keyboard_all_combinations "${filename}" "${FP_KB_DIR}" "${Keymap}" "${RunBuild}" "${ConvertTo}" "" "${UseDocker}"
        fi
    done
fi
