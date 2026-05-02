#ifdef RGB_MATRIX_FRAMEBUFFER_EFFECTS
// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(tetris_falling)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "eeprom.h"
#include "eeconfig.h"

/**
 * We store the data about the current state in the g_rgb_frame_buffer, provided by QMK
 * g_rgb_frame_buffer is an array of uint8_t of size ROW * COL
 *
 * The first 7 bits are used to determine the tetromino, as shown in the #defines below
 * X0000001 is the I_BLOCK, X0000010 is the J_BLOCK, X0000100 is the L_BLOCK, X0001000 is the O_BLOCK, etc...
 */


// https://qph.cf2.quoracdn.net/main-qimg-356e2b21c801381db2890dab49a9ea88
#define BIT_I_BLOCK 1
#define BIT_J_BLOCK 2
#define BIT_L_BLOCK 4
#define BIT_O_BLOCK 8
#define BIT_S_BLOCK 16
#define BIT_T_BLOCK 32
#define BIT_Z_BLOCK 64
#define BIT_ACTIVE_DROP 128

#define I_BLOCK_HUE 127 // cyan
#define J_BLOCK_HUE 169 // blue
#define L_BLOCK_HUE 21  // orange
#define O_BLOCK_HUE 43  // yellow
#define S_BLOCK_HUE 85  // green
#define T_BLOCK_HUE 180 // purple
#define Z_BLOCK_HUE 0   // red

#define T_CHK_YS 255
#define T_CHK_NO 0

/**
 * Get a random blocktype
 */
uint8_t get_random_blocktype(void) {
    // random 0-6
    uint8_t randomInt = rand() % 7;
    uint8_t blockType = 1;

    switch (randomInt) {
        case 0:
            blockType = BIT_I_BLOCK;
            break;
        case 1:
            blockType = BIT_J_BLOCK;
            break;
        case 2:
            blockType = BIT_L_BLOCK;
            break;
        case 3:
            blockType = BIT_O_BLOCK;
            break;
        case 4:
            blockType = BIT_S_BLOCK;
            break;
        case 5:
            blockType = BIT_T_BLOCK;
            break;
        case 6:
            blockType = BIT_Z_BLOCK;
            break;
        default:
            break;
    }

    return blockType;
}

/**
 * Get a blocktype column starting offset
 * Because the blocks have various widths, when we select a starting column at random, we want to make sure that the block doesn't extend past the right
 * side of the keyboard. So the offsets are based on the matrix definitions as found in get_tetromino_matrix()
 */
uint8_t get_blocktype_column_starting_offset(uint8_t blocktype) {
    uint8_t offset;

    switch (blocktype) {
        case BIT_I_BLOCK:
            offset = 3;
            break;
        case BIT_J_BLOCK:
            offset = 2;
            break;
        case BIT_L_BLOCK:
            offset = 2;
            break;
        case BIT_O_BLOCK:
            offset = 1;
            break;
        case BIT_S_BLOCK:
            offset = 2;
            break;
        case BIT_T_BLOCK:
            offset = 2;
            break;
        case BIT_Z_BLOCK:
            offset = 2;
            break;
        default:
            offset = 0;
    }

    return offset;
}

/**
 * Given a byte in the frame buffer, return the bit associated with the tetromino that it represents (e.g. values of BIT_I_BLOCK, BIT_J_BLOCK, etc)
 */
uint8_t get_t_blocktype_from_frame_buffer(uint8_t buffer_value) {
    // This mask will give you the 7 least significant bits of an 8 bit value only. So, 0b10010000 will return 0b00010000
    unsigned  mask;
    mask = (1 << 7) - 1;
    uint8_t tetromino_bit;
    tetromino_bit = buffer_value & mask;
    return tetromino_bit;
}

// Didn't end up needing this, since I just track the active block in the loop
// /**
//  * Given a byte in the frame buffer, return true if active, or false if inactive
//  */
// bool get_t_active_from_frame_buffer(uint8_t buffer_value) {
//     // This mask will give you the most significant bit of an 8 bit value only. So, either 0 or 128 for 0b0XXXXXXX or 0b1XXXXXXX, respectively
//     unsigned  mask;
//     mask = ((1 << 1) - 1) << 7;
//     uint8_t active_bit;
//     active_bit = buffer_value & mask;
//     if (active_bit == BIT_ACTIVE_DROP) {
//         return true;
//     } else {
//         return false;
//     }
// }

/**
 * Returns the hue of the block, based on the tetromino value passed in (BIT_I_BLOCK, BIT_J_BLOCK, etc)
 */
uint8_t get_t_hue(uint8_t tetromino_number) {
    uint8_t hue = 0;

    switch (tetromino_number) {
        case BIT_I_BLOCK:
            hue = I_BLOCK_HUE;
            break;
        case BIT_J_BLOCK:
            hue = J_BLOCK_HUE;
            break;
        case BIT_L_BLOCK:
            hue = L_BLOCK_HUE;
            break;
        case BIT_O_BLOCK:
            hue = O_BLOCK_HUE;
            break;
        case BIT_S_BLOCK:
            hue = S_BLOCK_HUE;
            break;
        case BIT_T_BLOCK:
            hue = T_BLOCK_HUE;
            break;
        case BIT_Z_BLOCK:
            hue = Z_BLOCK_HUE;
            break;
        default:
            break;
    }

    return hue;
}

/**
 * Returns a matrix of masked values (T_CHK_YS or T_CHK_NO) that can be used to merge into the RGB matrix buffer for collision testing, etc
 */
void get_tetromino_matrix(uint8_t (*tetromino_matrix)[4], uint8_t tetromino_number) {
    switch (tetromino_number) {
        case BIT_I_BLOCK:
            tetromino_matrix[0][0] = T_CHK_YS;
            tetromino_matrix[0][1] = T_CHK_YS;
            tetromino_matrix[0][2] = T_CHK_YS;
            tetromino_matrix[0][3] = T_CHK_YS;
            tetromino_matrix[1][0] = T_CHK_NO;
            tetromino_matrix[1][1] = T_CHK_NO;
            tetromino_matrix[1][2] = T_CHK_NO;
            tetromino_matrix[1][3] = T_CHK_NO;
            break;
        case BIT_J_BLOCK:
            tetromino_matrix[0][0] = T_CHK_YS;
            tetromino_matrix[0][1] = T_CHK_NO;
            tetromino_matrix[0][2] = T_CHK_NO;
            tetromino_matrix[0][3] = T_CHK_NO;
            tetromino_matrix[1][0] = T_CHK_YS;
            tetromino_matrix[1][1] = T_CHK_YS;
            tetromino_matrix[1][2] = T_CHK_YS;
            tetromino_matrix[1][3] = T_CHK_NO;
            break;
        case BIT_L_BLOCK:
            tetromino_matrix[0][0] = T_CHK_YS;
            tetromino_matrix[0][1] = T_CHK_YS;
            tetromino_matrix[0][2] = T_CHK_YS;
            tetromino_matrix[0][3] = T_CHK_NO;
            tetromino_matrix[1][0] = T_CHK_YS;
            tetromino_matrix[1][1] = T_CHK_NO;
            tetromino_matrix[1][2] = T_CHK_NO;
            tetromino_matrix[1][3] = T_CHK_NO;
            break;
        case BIT_O_BLOCK:
            tetromino_matrix[0][0] = T_CHK_YS;
            tetromino_matrix[0][1] = T_CHK_YS;
            tetromino_matrix[0][2] = T_CHK_NO;
            tetromino_matrix[0][3] = T_CHK_NO;
            tetromino_matrix[1][0] = T_CHK_YS;
            tetromino_matrix[1][1] = T_CHK_YS;
            tetromino_matrix[1][2] = T_CHK_NO;
            tetromino_matrix[1][3] = T_CHK_NO;
            break;
        case BIT_S_BLOCK:
            tetromino_matrix[0][0] = T_CHK_NO;
            tetromino_matrix[0][1] = T_CHK_YS;
            tetromino_matrix[0][2] = T_CHK_YS;
            tetromino_matrix[0][3] = T_CHK_NO;
            tetromino_matrix[1][0] = T_CHK_YS;
            tetromino_matrix[1][1] = T_CHK_YS;
            tetromino_matrix[1][2] = T_CHK_NO;
            tetromino_matrix[1][3] = T_CHK_NO;
             break;
        case BIT_T_BLOCK:
            tetromino_matrix[0][0] = T_CHK_NO;
            tetromino_matrix[0][1] = T_CHK_YS;
            tetromino_matrix[0][2] = T_CHK_NO;
            tetromino_matrix[0][3] = T_CHK_NO;
            tetromino_matrix[1][0] = T_CHK_YS;
            tetromino_matrix[1][1] = T_CHK_YS;
            tetromino_matrix[1][2] = T_CHK_YS;
            tetromino_matrix[1][3] = T_CHK_NO;
            break;
        case BIT_Z_BLOCK:
            tetromino_matrix[0][0] = T_CHK_YS;
            tetromino_matrix[0][1] = T_CHK_YS;
            tetromino_matrix[0][2] = T_CHK_NO;
            tetromino_matrix[0][3] = T_CHK_NO;
            tetromino_matrix[1][0] = T_CHK_NO;
            tetromino_matrix[1][1] = T_CHK_YS;
            tetromino_matrix[1][2] = T_CHK_YS;
            tetromino_matrix[1][3] = T_CHK_NO;

            break;
        default:
            tetromino_matrix[0][0] = T_CHK_NO;
            tetromino_matrix[0][1] = T_CHK_NO;
            tetromino_matrix[0][2] = T_CHK_NO;
            tetromino_matrix[0][3] = T_CHK_NO;
            tetromino_matrix[1][0] = T_CHK_NO;
            tetromino_matrix[1][1] = T_CHK_NO;
            tetromino_matrix[1][2] = T_CHK_NO;
            tetromino_matrix[1][3] = T_CHK_NO;
            break;
    }
}

/**
 * The main RGB effect function!
 */
static bool tetris_falling(effect_params_t* params) {
    // Initialize variables that are used across runs
    // Used to change the speed of the drops, larger speed increment is slower
    const uint8_t speed_increment = 100;
    static uint8_t increment = 0;

    static bool tetris_restart = true;
    static bool drop_active  = false;
    static uint8_t active_t_blocktype = 0;
    static uint8_t active_t_col = 0;
    static uint8_t active_t_row = 0;
    // TODO: REPLACE MATRIX_ROWS AND MATRIX_COLS WITH NEW CONCEPT CALLED MATRIX_PHYSICAL_ROWS AND MATRIX_PHYSICAL_COLS
    static uint8_t g_rgb_frame_buffer_copy[MATRIX_ROWS][MATRIX_COLS] = {{0}};

    // Put the whole thing in an if block to slow it down
    if (++increment > speed_increment) {
        // Either this is the first time we run, or the last loop resulted in a collision, so we restarted
        if (tetris_restart) {
            rgb_matrix_set_color_all(0, 0, 0);
            memset(g_rgb_frame_buffer, 0, sizeof(g_rgb_frame_buffer));
            drop_active = false;
            tetris_restart = false;
        }

        // The previous turn resulted in a settled tetromino, so need a new piece to drop. Randomly select piece and column to drop in
        if (!drop_active) {
            active_t_blocktype = get_random_blocktype();
            active_t_col = rand() % (MATRIX_COLS - get_blocktype_column_starting_offset(active_t_blocktype));
            active_t_row = 0;
            drop_active = true;
        }

        /**
         * Let's merge the tetromino into a copy of the buffer, and check for collisions
         * If there is no collision, we render it and wait for the next loop
         * If there is a collision, then...
         *      * If any part of the tetromino is "off screen", we don't render and restart
         *      * If no part of the tetromino is "off screen", then we make it permanent in the buffer (not the copy), and set drop_active to false so we can get a new block on the next run
         */

        // Make a copy of the buffer for this iteration
        memcpy(g_rgb_frame_buffer_copy, g_rgb_frame_buffer, sizeof(g_rgb_frame_buffer));

        // get the tetromino matrix
        uint8_t active_t_block_matrix[2][4] = {{0}};
        get_tetromino_matrix(active_t_block_matrix, active_t_blocktype);

        /**
         * Possible conditions to check for:
         * - The block has collisions with another block
         *   - If a collision with another block, we move it back up 1 to draw.
         *     - If after moving back up one, it's not off screen on top (row >= 0), then we drop a new block (set drop_active to false)
         *     - If after moving it back up one, it's off screen on top (row < 0), then we restart tetris
         * - The block doesn't have a collision, but is now off screen at the bottom (row > MATRIX_PHYSICAL_ROWS)
         *   - We go back up one, and drop a new block (set drop_active to false)
         */

        // We'll use this subtract to shift up in case there is a collision for the last redraw
        uint8_t subtract = 0;
        for (uint8_t check_col = 0; check_col <= get_blocktype_column_starting_offset(active_t_blocktype); check_col++) {
            for (uint8_t check_row = 0; check_row <= 1; check_row++) {
                if (active_t_block_matrix[check_row][check_col] == T_CHK_YS) {
                    // Bounds check before array access: if the block extends past the bottom, treat as no-collision settle
                    if (active_t_row + check_row >= MATRIX_ROWS) {
                        subtract = 1;
                        drop_active = false;
                        continue;
                    }
                    if ((active_t_block_matrix[check_row][check_col] & g_rgb_frame_buffer_copy[active_t_row+check_row][active_t_col+check_col]) == 0) {
                        // If we're here, no collision
                        if (active_t_row >= (MATRIX_ROWS-1)) {
                            // If we're in here, then we have gone past the bottom row. We can't drop anymore, so we subtract 1 and drop a new tetromino
                            subtract = 1;
                            drop_active = false;
                        }

                        // If the Led count at this location is 0, then we actually hit a collision with a spot that has no LED!
                        // Note. This may be a problem for push button encoders in the middle of the switch matrix. Really need to convert this to MATRIX_PHYSICAL_ROWS and MATRIX_PHYSICAL_COLS :(
                        uint8_t led[LED_HITS_TO_REMEMBER];
                        uint8_t led_count = rgb_matrix_map_row_column_to_led(active_t_row+check_row, active_t_col+check_col, led);
                        if (led_count == 0) {
                            subtract = 1;
                            drop_active = false;
                        }
                    } else {
                        // If we're here yes collision
                        if (active_t_row > 0) {
                            // If we're here, then we're on the first row, and we can safely subtract 1 for the draw
                            subtract = 1;
                            // We set drop_active to false so we can start over
                            drop_active = false;
                        } else {
                            // If we're here, we're on the first row, so we subtract 1 and partially draw below (need error checking for negative numbers!), and we've now placed the last teromino
                            // at the top, so the game is over
                            tetris_restart = true;
                        }
                    }
                }
            }
        }

        // Now that we've done all the logic above, we can draw it!
        for (uint8_t check_col = 0; check_col <= get_blocktype_column_starting_offset(active_t_blocktype); check_col++) {
            for (uint8_t check_row = 0; check_row <= 1; check_row++) {
                if (active_t_block_matrix[check_row][check_col] == T_CHK_YS) {
                    // This if condition is just to check to make sure that we don't try to draw above the top row
                    // This is a possibility if the last tetromino had a block that had a collision that left the top part of it in row -1
                    if ( (int16_t)(active_t_row+check_row-subtract) >= 0) {
                        g_rgb_frame_buffer_copy[active_t_row+check_row-subtract][active_t_col+check_col] = active_t_blocktype;
                    }
                }
            }
        }

        // for (uint8_t check_col = 0; check_col <= get_blocktype_column_starting_offset(active_t_blocktype); check_col++) {
        //     for (uint8_t check_row = 0; check_row <= 1; check_row++) {
        //         // if the tetromino block matrix has a block in this spot, we check for a collision
        //         if (active_t_block_matrix[check_row][check_col] == T_CHK_YS) {
        //             // TODO: check if an LED exists in all of the spots that there is a T_CHK_YS for this block type, it's possible there is a NO_LED in the <keyboard_name>.c led config...

        //             if ((active_t_block_matrix[check_row][check_col] & g_rgb_frame_buffer_copy[active_t_row+check_row][active_t_col+check_col]) == 0) {
        //                 // no collision, but check if wen't off screen at the bottom
        //                 // TODO: This doesn't work, need to check for "NO_LED" based on the MATRIX_PHYSICAL_ROW and MATRIX_PHYSICAL_COL once implemented
        //                 if (active_t_col+check_col > MATRIX_COLS) { // TODO: REPLACE MATRIX_ROWS AND MATRIX_COLS WITH NEW CONCEPT CALLED MATRIX_PHYSICAL_ROWS AND MATRIX_PHYSICAL_COLS
        //                     // we went off screen at the bottom, so we sutract 1 from the row and do another drop
        //                     active_t_row -= 1;
        //                     drop_active = false;
        //                 }
        //             } else {
        //                 // we have a collision... subtract 1 from the row and...
        //                 if (active_t_row > 0) { // TODO: REPLACE MATRIX_ROWS AND MATRIX_COLS WITH NEW CONCEPT CALLED MATRIX_PHYSICAL_ROWS AND MATRIX_PHYSICAL_COLS
        //                     // if nothing is off screen, we write the previous state (-1 column) to the main buffer, and do another drop
        //                     active_t_row -= 1;
        //                     drop_active = false;
        //                 } else {
        //                     // if anything is off screen, draw as is and restart the whole thing
        //                     tetris_restart = true;
        //                 }
        //             }

        //             g_rgb_frame_buffer_copy[active_t_row+check_row][active_t_col+check_col] = active_t_blocktype;
        //         }

        //         if (drop_active == false || tetris_restart == true) {
        //             break;
        //         }
        //     }
        //     if (drop_active == false || tetris_restart == true) {
        //         break;
        //     }
        // }

        // Now we merge the current state with the g_rgb_frame_buffer (not the copy, and we only persist it if the drop_active is false, so the blocks move down) and draw it to the led matrix
        if (drop_active == false) {
            // we persist it, since we hit a collision, but we didn't have to restart tetris
            memcpy(g_rgb_frame_buffer, g_rgb_frame_buffer_copy, sizeof(g_rgb_frame_buffer_copy));
        }

        // first we need to clear before redrawing to make sure we don't leave a trail on the actively dropping block
        rgb_matrix_set_color_all(0, 0, 0);
        
        // TODO: REPLACE MATRIX_ROWS AND MATRIX_COLS WITH NEW CONCEPT CALLED MATRIX_PHYSICAL_ROWS AND MATRIX_PHYSICAL_COLS
        // Now draw the whole thing based on g_rgb_frame_buffer_copy
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
                if (g_rgb_frame_buffer_copy[row][col] != 0) {

                    uint8_t led[LED_HITS_TO_REMEMBER];
                    // TODO: after changing to MATRIX_PHYSICAL_ROWS and MATRIX_PHYSICAL_COLS, update this to set the correct led number
                    uint8_t led_count = rgb_matrix_map_row_column_to_led(row, col, led);

                    // TODO: multiple leds are supported mapped to the same row/column
                    if (led_count > 0) {
                        uint8_t curr_hue = get_t_hue(g_rgb_frame_buffer_copy[row][col]);
                        HSV curr_hsv = { .h = curr_hue, .s = 255, .v = 255 };
                        RGB curr_rgb = hsv_to_rgb(curr_hsv);
                        rgb_matrix_set_color(led[0], curr_rgb.r, curr_rgb.g, curr_rgb.b);
                    }
                }
            }
        }

        // We increment the row for the next loop
        active_t_row += 1;

        // we landed in here, so let's reset the increment to 0... this is only to throttle speed
        increment = 0;
    } // Speed increment

    return false;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif // RGB_MATRIX_FRAMEBUFFER_EFFECTS
