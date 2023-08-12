# fingerpunch keyboards

## Building

For general firmware build walkthrough and instructions, please see:  
[FIRMWARE.md](FIRMWARE.md)

## Operating system

| Setting                                 | Description                                                                                                                  | Default                          |
| --------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------- | -------------------------------- |
| `FP_MAC_PREFERRED`                      | (Optional) If you are primarily using a Mac, enable to use Mac specific logic for fingerpunch features (mostly for keycodes) | `undefined`                      |

## Keycodes and settings

### Settings

| Setting                                 | Description                                                                                                   | Default                          |
| --------------------------------------- | ------------------------------------------------------------------------------------------------------------- | -------------------------------- |
| `FP_DISABLE_CUSTOM_KEYCODES`            | (Optional) Disables all the custom keycodes defined in the Keycodes section on this page                      | `undefined`                      |
| `FP_SUPER_TAB_TIMEOUT`                  | (Required) Sets the timeout (in milliseconds) for the alt tab (using keycode `FP_SUPER_TAB`) to go away       | `500`                            |
| `FP_SUPER_CTRL_TAB_TIMEOUT`             | (Required) Sets the timeout (in milliseconds) for the ctrl tab (using keycode `FP_SUPER_CTRL_TAB`) to go away | `750`                            |

### Keycodes

**Note: Pointing device DPI is specified in increments of 1, but is multiplied by 100 when applied. So, a DPI of 3 would be 300**

| Key                            | Category           | Description                                                                                                                                                                                   |
| ------------------------------ | -------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `FP_ACCEL_TOG`                 | Pointing Device    | Toggle pointing device acceleration (default is enabled on keyboard startup)                                                                                                                  |
| `FP_POINT_DPI_UP`              | Pointing Device    | Increase the pointing DPI (increments of 1, maximum `FP_POINTING_MAX_DPI`)                                                                                                                    |
| `FP_POINT_DPI_DN`              | Pointing Device    | Decrease the pointing DPI (increments of 1, minimum `FP_POINTING_MIN_DPI`)                                                                                                                    |
| `FP_POINT_DPI_RESET`           | Pointing Device    | Reset the pointing DPI back to the default (defined as value of `FP_POINTING_DEFAULT_DPI`)                                                                                                    |
| `FP_SCROLL_TOG`                | Pointing Device    | Toggle scrolling mode                                                                                                                                                                         |
| `FP_SCROLL_ON`                 | Pointing Device    | Turn on scrolling mode                                                                                                                                                                        |
| `FP_SCROLL_OFF`                | Pointing Device    | Turn off scrolling mode                                                                                                                                                                       |
| `FP_SCROLL_MOMENT`             | Pointing Device    | Activate scrolling mode while holding this key (this is a mouse key, it keeps the auto mouse layer active when held)                                                                          |
| `FP_SCROLL_DPI_UP`             | Pointing Device    | Increase the scrolling DPI (increments of 1, maximum `FP_POINTING_SCROLLING_MAX_DPI`)                                                                                                         |
| `FP_SCROLL_DPI_DN`             | Pointing Device    | Decrease the scrolling DPI (increments of 1, minimum `FP_POINTING_SCROLLING_MIN_DPI`)                                                                                                         |
| `FP_SCROLL_DPI_RESET`          | Pointing Device    | Reset the scrolling DPI back to the default (defined as value of `FP_POINTING_SCROLLING_DPI`)                                                                                                 |
| `FP_SNIPE_TOG`                 | Pointing Device    | Toggle sniping mode                                                                                                                                                                           |
| `FP_SNIPE_ON`                  | Pointing Device    | Turn on sniping mode                                                                                                                                                                          |
| `FP_SNIPE_OFF`                 | Pointing Device    | Turn off sniping mode                                                                                                                                                                         |
| `FP_SNIPE_MOMENT`              | Pointing Device    | Activate sniping mode while holding this key (this is a mouse key, it keeps the auto mouse layer active when held)                                                                            |
| `FP_SNIPE_DPI_UP`              | Pointing Device    | Increase the sniping DPI (increments of 1, maximum `FP_POINTING_SNIPING_MAX_DPI`)                                                                                                             |
| `FP_SNIPE_DPI_DN`              | Pointing Device    | Decrease the sniping DPI (increments of 1, minimum `FP_POINTING_SNIPING_MIN_DPI`)                                                                                                             |
| `FP_SNIPE_DPI_RESET`           | Pointing Device    | Reset the sniping DPI back to the default (defined as value of `FP_POINTING_SNIPING_DPI`)                                                                                                     |
| `FP_ZOOM_TOG`                  | Pointing Device    | Toggle zooming mode                                                                                                                                                                           |
| `FP_ZOOM_ON`                   | Pointing Device    | Turn on zooming mode                                                                                                                                                                          |
| `FP_ZOOM_OFF`                  | Pointing Device    | Turn off zooming mode                                                                                                                                                                         |
| `FP_ZOOM_MOMENT`               | Pointing Device    | Activate zooming mode while holding this key (this is a mouse key, it keeps the auto mouse layer active when held)                                                                            |
| `FP_SUPER_TAB`                 | Other              | Super alt tab, tap to alt tab instead of holding alt, supports holding shift to alt tab backwards (to use on Mac, see `FP_MAC_PREFERRED` and see `FP_SUPER_TAB_TIMEOUT` to change timeout)    |
| `FP_SUPER_CTRL_TAB`            | Other              | Super ctrl tab, tap to ctrl tab instead of holding ctrl, supports holding shift to ctrl tab backwards (see `FP_SUPER_TAB_TIMEOUT` to change timeout)                                          |

Note: if you are using a userspace, and you have custom keycodes, you will need to add some logic in your userspace keycodes .h file that will handle the `SAFE_RANGE` appropriately.

```C
// Check to see which keyboard you're using, and define the PLACEHOLDER_SAFE_RANGE based on that.
#if defined(KEYBOARD_fingerpunch_arachnophobe) \
    || defined(KEYBOARD_fingerpunch_barobord) \
    || defined(KEYBOARD_fingerpunch_barobord_byomcu) \
    || defined(KEYBOARD_fingerpunch_bgkeeb) \
    || defined(KEYBOARD_fingerpunch_bigbarobord) \
    || defined(KEYBOARD_fingerpunch_euclid36) \
    || defined(KEYBOARD_fingerpunch_euclid36_proto) \
    || defined(KEYBOARD_fingerpunch_ffkb_atmega_v1) \
    || defined(KEYBOARD_fingerpunch_ffkb_byomcu_v1) \
    || defined(KEYBOARD_fingerpunch_ffkb_byomcu_v2) \
    || defined(KEYBOARD_fingerpunch_ffkb_byomcu_v3) \
    || defined(KEYBOARD_fingerpunch_ffkb_rp_v3) \
    || defined(KEYBOARD_fingerpunch_fflx) \
    || defined(KEYBOARD_fingerpunch_fpm101) \
    || defined(KEYBOARD_fingerpunch_luakeeb) \
    || defined(KEYBOARD_fingerpunch_pinkiesout_v1) \
    || defined(KEYBOARD_fingerpunch_pinkiesout_v2) \
    || defined(KEYBOARD_fingerpunch_rockon_v1) \
    || defined(KEYBOARD_fingerpunch_rockon_v2) \
    || defined(KEYBOARD_fingerpunch_rockon_v3) \
    || defined(KEYBOARD_fingerpunch_rockon_bp) \
    || defined(KEYBOARD_fingerpunch_sweeeeep) \
    || defined(KEYBOARD_fingerpunch_ximi)
#    define PLACEHOLDER_SAFE_RANGE FP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
    YOUR_KEYCODE_1 = PLACEHOLDER_SAFE_RANGE,
    YOUR_KEYCODE_2,
...
    NEW_SAFE_RANGE,
}
```

## Encoders

The fingerpunch firmware has some pre-defined encoder behaviors, which you can specify on a per encoder and per layer basis. See the table below. If you wanted the first encoder (encoder 0) to behave as DPI pointing on layer 2, you'd set `#define FP_ENC_0_LAYER_DPI_POINTING 2` in your config.h

If you don't want to use this functionality, you can override it by creating your own `encoder_update_user()` function and return false at the end. This will bypass the fingerpunch encoder logic.

For example:
```c
bool encoder_update_kb(uint8_t index, bool clockwise) {
    // Your encoder logic goes here
    
    // return false to avoid processing the encoder_update_kb() function that fingerpunch uses
    return false;
}
```

**Please note that there cannot be duplicate values per encoder config.** Below is an example of a configuration that will work. Note that you aren't limited to 0-6. If you have 8 or 9 layers, you can specify any layer, as long as none have the same layer value.

```c
#define FP_ENC_0_LAYER_VOLUME         6
#define FP_ENC_0_LAYER_PGUP_PGDN      4
#define FP_ENC_0_LAYER_ZOOM           3
#define FP_ENC_0_LAYER_DPI_POINTING   0
#define FP_ENC_0_LAYER_SUPER_TAB      1
#define FP_ENC_0_LAYER_SUPER_CTRL_TAB 2
#define FP_ENC_0_LAYER_SCROLL_WHEEL   5
#define FP_ENC_0_LAYER_RGB_MODE       7
#define FP_ENC_0_LAYER_RGB_HUE        8
#define FP_ENC_0_LAYER_RGB_SAT        9
#define FP_ENC_0_LAYER_RGB_VAL        10

#define FP_ENC_1_LAYER_SUPER_TAB      4
#define FP_ENC_1_LAYER_PGUP_PGDN      6
#define FP_ENC_1_LAYER_ZOOM           3
#define FP_ENC_1_LAYER_DPI_POINTING   1
#define FP_ENC_1_LAYER_SUPER_CTRL_TAB 5
#define FP_ENC_1_LAYER_SCROLL_WHEEL   2
#define FP_ENC_1_LAYER_VOLUME         0
#define FP_ENC_1_LAYER_RGB_MODE       7
#define FP_ENC_1_LAYER_RGB_HUE        8
#define FP_ENC_1_LAYER_RGB_SAT        9
#define FP_ENC_1_LAYER_RGB_VAL        10
```

| Setting                                      | Description                                                                                                                 | Default               |
| -------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------- | --------------------- |
| `FP_ENC_0_LAYER_VOLUME`                      | Clockwise volume up, counter clockwise volume down                                                                          | `0`                   |
| `FP_ENC_0_LAYER_PGUP_PGDN`                   | Clockwise page up, counter clockwise page down                                                                              | `1`                   |
| `FP_ENC_0_LAYER_ZOOM`                        | Clockwise zoom in, counter clockwise zoom out                                                                               | `2`                   |
| `FP_ENC_0_LAYER_DPI_POINTING`                | Clockwise DPI pointing value up, counter clockwise DPI pointing value down                                                  | `3`                   |
| `FP_ENC_0_LAYER_SUPER_TAB`                   | Clockwise cmd/alt tab, counter clockwise shift cmd/alt tab (see `FP_MAC_PREFERRED` to determine if it uses cmd or alt)      | `4`                   |
| `FP_ENC_0_LAYER_SUPER_CTRL_TAB`              | Clockwise ctrl tab, counter clockwise volume down                                                                           | `5`                   |
| `FP_ENC_0_LAYER_SCROLL_WHEEL`                | Clockwise scroll wheel down, counter clockwise scroll wheel down                                                            | `6`                   |
| `FP_ENC_0_LAYER_RGB_MODE`                    | Clockwise to step forward in RGB mode, counter clockwise to step backwards in RGB mode                                      | `7`                   |
| `FP_ENC_0_LAYER_RGB_HUE`                     | Clockwise to increase RGB hue, counter clockwise to decrease RGB hue                                                        | `8`                   |
| `FP_ENC_0_LAYER_RGB_SAT`                     | Clockwise to increase RGB saturation, counter clockwise to decrease RGB saturation                                          | `9`                   |
| `FP_ENC_0_LAYER_RGB_VAL`                     | Clockwise to increase RGB value (typically brightness), counter clockwise to decrease RGB value                             | `10`                  |
| `FP_ENC_1_LAYER_SUPER_TAB`                   | Same as `FP_ENC_0_LAYER_SUPER_TAB`, but for encoder 1                                                                       | `0`                   |
| `FP_ENC_1_LAYER_PGUP_PGDN`                   | Same as `FP_ENC_0_LAYER_PGUP_PGDN`, but for encoder 1                                                                       | `1`                   |
| `FP_ENC_1_LAYER_ZOOM`                        | Same as `FP_ENC_0_LAYER_ZOOM`, but for encoder 1                                                                            | `2`                   |
| `FP_ENC_1_LAYER_DPI_POINTING`                | Same as `FP_ENC_0_LAYER_DPI_POINTING`, but for encoder 1                                                                    | `3`                   |
| `FP_ENC_1_LAYER_SUPER_CTRL_TAB`              | Same as `FP_ENC_0_LAYER_SUPER_CTRL_TAB`, but for encoder 1                                                                  | `4`                   |
| `FP_ENC_1_LAYER_SCROLL_WHEEL`                | Same as `FP_ENC_0_LAYER_SCROLL_WHEEL`, but for encoder 1                                                                    | `5`                   |
| `FP_ENC_1_LAYER_VOLUME`                      | Same as `FP_ENC_0_LAYER_VOLUME`, but for encoder 1                                                                          | `6`                   |
| `FP_ENC_1_LAYER_RGB_MODE`                    | Same as `FP_ENC_0_LAYER_RGB_MODE`, but for encoder 1                                                                        | `7`                   |
| `FP_ENC_1_LAYER_RGB_HUE`                     | Same as `FP_ENC_0_LAYER_RGB_HUE`, but for encoder 1                                                                         | `8`                   |
| `FP_ENC_1_LAYER_RGB_SAT`                     | Same as `FP_ENC_0_LAYER_RGB_SAT`, but for encoder 1                                                                         | `9`                   |
| `FP_ENC_1_LAYER_RGB_VAL`                     | Same as `FP_ENC_0_LAYER_RGB_VAL`, but for encoder 1                                                                         | `10`                  |

## Pointing Device

### General Settings

**Note: Pointing device DPI is specified in increments of 1, but is multiplied by 100 when applied. So, a DPI of 3 would be 300**

| Setting                                      | Description                                                                                                                 | Default                          |
| -------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------- | -------------------------------- |
| `FP_POINTING_EXTENDED_MOUSE_REPORT_DISABLE`  | (Optional) Disable extended mouse report, enabled by default when pointing devices is enabled, saves a tiny bit of memory   | `undefined`                      |
| `FP_POINTING_DEFAULT_DPI`                    | (Required) Sets the default DPI for your pointing device                                                                    | `10`                             |
| `FP_POINTING_MIN_DPI`                        | (Required) Sets the minimum DPI for your pointing device                                                                    | `2`                              |
| `FP_POINTING_MAX_DPI`                        | (Required) Sets the maximum DPI for your pointing device                                                                    | `60`                             |
| `FP_POINTING_SCROLLING_DPI`                  | (Required) Sets the default DPI for scrolling                                                                               | `2`                              |
| `FP_POINTING_SCROLLING_MIN_DPI`              | (Required) Sets the minimum DPI for scrolling                                                                               | `2`                              |
| `FP_POINTING_SCROLLING_MAX_DPI`              | (Required) Sets the maximum DPI for scrolling                                                                               | `10`                             |
| `FP_POINTING_SCROLLING_LAYER_ENABLE`         | (Optional) Enables scrolling mode for the layer `FP_POINTING_SCROLLING_LAYER`                                               | `undefined`                      |
| `FP_POINTING_SCROLLING_LAYER`                | (Required) Defines the layer used to enable scrolling                                                                       | `3`                              |
| `FP_POINTING_SNIPING_DPI`                    | (Required) Sets the default DPI for sniping                                                                                 | `2`                              |
| `FP_POINTING_SNIPING_MIN_DPI`                | (Required) Sets the minimum DPI for sniping                                                                                 | `2`                              |
| `FP_POINTING_SNIPING_MAX_DPI`                | (Required) Sets the maximum DPI for sniping                                                                                 | `5`                              |
| `FP_POINTING_SNIPING_LAYER_ENABLE`           | (Required) Enables sniping mode for the layer `FP_POINTING_SNIPING_LAYER`                                                   | `undefined`                      |
| `FP_POINTING_SNIPING_LAYER`                  | (Required) Defines the layer used to enable sniping                                                                         | `2`                              |
| `FP_POINTING_ZOOMING_LAYER_ENABLE`           | (Required) Enables zooming mode for the layer `FP_POINTING_ZOOMING_LAYER`                                                   | `undefined`                      |
| `FP_POINTING_ZOOMING_LAYER`                  | (Required) Defines the layer used to enable zooming                                                                         | `1`                              |
| `FP_POINTING_ACCELERATION_ENABLE`            | (Optional) (EXPERIMENTAL) Enable pointing device acceleration                                                               | `undefined`                      |
| `FP_SLOW_SCROLL`                             | (Optional) Slow down the scrolling speed by a factor of `FP_SLOW_SCROLL_DENOMINATOR`                                        | `undefined`                      |
| `FP_SLOW_SCROLL_DENOMINATOR`                 | (Optional) When `FP_SLOW_SCROLL` is defined, reduce the speed of scrolling by `FP_SLOW_SCROLL_DENOMINATOR`                  | `undefined`                      |
     


### Combined Pointing Devices

This only applies if you are using a split fingerpunch keyboard with two pointing devices. The default is for the left one to be scrolling, and the right one to act as the mouse, but this is configurable via the settings below. The compiler will error out if you specify both scrolling and sniping on the same side. For example, setting `FP_POINTING_COMBINED_SCROLLING_LEFT` and `FP_POINTING_COMBINED_SNIPING_LEFT` will fail.

| Setting                                 | Description                                                         | Default                    |
| --------------------------------------- | ------------------------------------------------------------------- | -------------------------- |
| `FP_POINTING_COMBINED_SCROLLING_LEFT`   | (Required) Sets default behavior to scrolling on the left half      | `true`                     |
| `FP_POINTING_COMBINED_SCROLLING_RIGHT`  | (Required) Sets default behavior to scrolling on the right half     | `false`                    |
| `FP_POINTING_COMBINED_SNIPING_LEFT`     | (Required) Sets default behavior to sniping on the left half        | `false`                    |
| `FP_POINTING_COMBINED_SNIPING_RIGHT`    | (Required) Sets default behavior to sniping on the right half       | `false`                    |


### Auto mouse layer

As of 2022-09-26, this has been pulled in early from qmk develop, but should be available in the Q4 release. See the documentation here:
https://github.com/qmk/qmk_firmware/blob/develop/docs/feature_pointing_device.md#automatic-mouse-layer-idpointing-device-auto-mouse

This is fully supported. Once I merge the next major release in Q4, I will remove this documentation.

In addition to the default configurations, there are additional features added to fingerpunch keyboards:

| Setting                                          | Description                                                                     | Default                         |
| ------------------------------------------------ | ------------------------------------------------------------------------------- | ------------------------------- |
| `FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY`            | (Required) Trackball auto mouse sensitivity value                               | `3`                             |

(Additional auto mouse configuration in the layer lighting section)

More detail on `FP_AUTO_MOUSE_TRACKBALL_SENSITIVITY`. If you are experiencing that the auto mouse layer triggers while typing, you can adjust this value. The default for for the core qmk feature is 0, which works great for trackpads. As you increase, it will require more mouse movement to trigger auto mouse layer. The default for trackballs on fingerpunch keyboards is 3. This value is only applied if you are using a trackball, and is otherwise ignored.

Note that I'm automatically enabling the feature if you add the `POINTING_DEVICE_AUTO_MOUSE_ENABLE` and `AUTO_MOUSE_DEFAULT_LAYER` to your config.h, such that you don't have to add this code:
```c
// in keymap.c:
void pointing_device_init_user(void) {
    set_auto_mouse_layer(<mouse_layer>); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}
```

## RGB Lighting

Notes:
* Unless otherwise specified, features for rgb are supported on both rgblight ( https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md ) and rgb matrix ( https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgb_matrix.md ).
* The base layer is still configurable using the QMK rgb keycodes ( https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md#keycodes ). If you want the base layer to be static, you will need to define the `FP_LAYER_LIGHTING_DYNAMIC_BASE_LAYER_DISABLE` config.

Some config parameters will depend on which you're using, like `FP_LAYER_LIGHTING_MODE`.

### Layer lighting

Please note that the `FP_LAYER_LIGHTING_AUTO_MOUSE_ENABLE` will be automatically disabled unless you define `FP_LAYER_LIGHTING_DISABLE`. Given that this fingerpunch layer lighting will handle the auto mouse layer as well, you don't need to activate the layer lighting twice. Just set the mouse layer lighting to the color you prefer using the `FP_LAYER_LIGHTING_HUE_X` below.

| Setting                                         | Description                                                                        | Default                                                      |
| ----------------------------------------------- | ---------------------------------------------------------------------------------- | ------------------------------------------------------------ |
| `FP_STARTUP_ANIMATION_DISABLE`                  | (Optional) Define this to disable startup animation                                |                                                              |
| `FP_LAYER_LIGHTING_DISABLE`                     | (Optional) Define this to disable layer lighting                                   | `undefined`                                                  |
| `FP_LAYER_LIGHTING_DYNAMIC_BASE_LAYER_DISABLE`  | (Optional) While using layer lighting, disable dynamically changing the base layer | `undefined`                                                  |
| `FP_LAYER_LIGHTING_MODE`                        | (Required) Set the layer lighting default mode                                     | `RGBLIGHT_MODE_STATIC_LIGHT` or `RGB_MATRIX_SOLID_COLOR`     |
| `FP_LAYER_LIGHTING_HUE_0`                       | (Required) Set the layer lighting hue for layer 0                                  | `HSV_BLUE`                                                   |
| `FP_LAYER_LIGHTING_HUE_1`                       | (Required) Set the layer lighting hue for layer 1                                  | `HSV_WHITE`                                                  |
| `FP_LAYER_LIGHTING_HUE_2`                       | (Required) Set the layer lighting hue for layer 2                                  | `HSV_GREEN`                                                  |
| `FP_LAYER_LIGHTING_HUE_3`                       | (Required) Set the layer lighting hue for layer 3                                  | `HSV_PURPLE`                                                 |
| `FP_LAYER_LIGHTING_HUE_4`                       | (Required) Set the layer lighting hue for layer 4                                  | `HSV_YELLOW`                                                 |
| `FP_LAYER_LIGHTING_HUE_5`                       | (Required) Set the layer lighting hue for layer 5                                  | `FP_HSV_MELON`                                               |
| `FP_LAYER_LIGHTING_HUE_6`                       | (Required) Set the layer lighting hue for layer 6                                  | `HSV_CYAN`                                                   |
| `FP_LAYER_LIGHTING_HUE_7`                       | (Required) Set the layer lighting hue for layer 7                                  | `HSV_SPRINGGREEN`                                            |
| `FP_LAYER_LIGHTING_MODE_0`                      | (Required) Set the layer lighting mode for layer 0                                 | `FP_LAYER_LIGHTING_MODE`                                     |
| `FP_LAYER_LIGHTING_MODE_1`                      | (Required) Set the layer lighting mode for layer 1                                 | `FP_LAYER_LIGHTING_MODE`                                     |
| `FP_LAYER_LIGHTING_MODE_2`                      | (Required) Set the layer lighting mode for layer 2                                 | `FP_LAYER_LIGHTING_MODE`                                     |
| `FP_LAYER_LIGHTING_MODE_3`                      | (Required) Set the layer lighting mode for layer 3                                 | `FP_LAYER_LIGHTING_MODE`                                     |
| `FP_LAYER_LIGHTING_MODE_4`                      | (Required) Set the layer lighting mode for layer 4                                 | `FP_LAYER_LIGHTING_MODE`                                     |
| `FP_LAYER_LIGHTING_MODE_5`                      | (Required) Set the layer lighting mode for layer 5                                 | `FP_LAYER_LIGHTING_MODE`                                     |
| `FP_LAYER_LIGHTING_MODE_6`                      | (Required) Set the layer lighting mode for layer 6                                 | `FP_LAYER_LIGHTING_MODE`                                     |
| `FP_LAYER_LIGHTING_MODE_7`                      | (Required) Set the layer lighting mode for layer 7                                 | `FP_LAYER_LIGHTING_MODE`                                     |
| `FP_LAYER_LIGHTING_CAPS_LOCK_HUE`               | (Required) Set the layer lighting hue when caps lock is enabled                    | `HSV_RED`                                                    |
| `FP_LAYER_LIGHTING_CAPS_LOCK_MODE`              | (Required) Set the layer lighting mode when caps lock is enabled                   | `FP_LAYER_LIGHTING_MODE`                                     |
| `FP_LAYER_LIGHTING_AUTO_MOUSE_ENABLE`           | (Optional) If using RGB, set the layer lighting when auto mouse is triggered       | `undefined`                                                  |
| `FP_LAYER_LIGHTING_AUTO_MOUSE_HUE`              | (Required) This is the hue that is used for the auto mouse layer lighting          | `HSV_ORANGE`                                                 |
| `FP_LAYER_LIGHTING_AUTO_MOUSE_MODE`             | (Required) This is the mode that is used for the auto mouse layer lighting         | `FP_LAYER_LIGHTING_MODE`                                     |

### Additional colors

| Define                | HSV               | Reference                                             |
| --------------------- | ----------------- | ----------------------------------------------------- |
| `FP_HSV_LAVENDER`     | `184, 200, 255`   | https://encycolorpedia.com/ccb3ff                     |
| `FP_HSV_LEMON`        |  `43, 200, 255`   | https://encycolorpedia.com/ffff9f                     |
| `FP_HSV_LIME`         |  `63, 225, 255`   | https://encycolorpedia.com/9efd38                     |
| `FP_HSV_MELON`        |   `0, 180, 255`   | https://encycolorpedia.com/febaad                     |
| `FP_HSV_MINT`         |  `84, 185, 255`   | https://encycolorpedia.com/98ff98                     |
| `FP_HSV_PEACH_ORANGE` |  `21, 205, 255`   | https://encycolorpedia.com/ffcc99                     |

### Vial only

If you are using vial on an `RGB_MATRIX_ENABLE` build, you may want to add support to control RGB settings within vial. You can do so by adding the following line to `{keyboard}/keymaps/vial/vial.json`  

```
{
  "name": "ffkb",
  "vendorId": "0xFEFE",
  "productId": "0xFFBB",
  "matrix": {"rows": 6, "cols": 8},
  "lighting": "vialrgb",  // <--- add this line here
  "layouts": {
    "labels": [
      ["Layout"]
    ],
    "keymap": [
      [
```


## Haptic Feedback

Enable special haptic feedback features.

Note that the ctrl-X haptic feedback responses will use control as the modifier, so it won't work on a Mac by default. However, if are primarily using a Mac, enable the `FP_MAC_PREFERRED` in your config.h

| Setting                                 | Description                                                                     | Default                         |
| --------------------------------------- | ------------------------------------------------------------------------------- | ------------------------------- |
| `FP_HAPTIC_MOUSE_BUTTONS`               | (Optional) Enable haptic feedback response for Mouse 1, 2, and 3                | `undefined`                     |
| `FP_HAPTIC_CUT_COPY_PASTE`              | (Optional) Enable haptic feedback response for ctrl-x, ctrl-c, ctrl-v           | `undefined`                     |
| `FP_HAPTIC_SAVE`                        | (Optional) Enable haptic feedback response for ctrl-s                           | `undefined`                     |

### get_haptic_enabled_key override

When using a fingerpunch board, the get_haptic_enabled_key is completely overridden such that all haptic is disabled for all keys. This is because the default implementation allows you to disable certain keys, but leaves you with a majority of keypresses generating haptic feedback. This means that you cannot use the QMK config options:
* NO_HAPTIC_MOD
* NO_HAPTIC_ALPHA
* NO_HAPTIC_PUNCTUATION
* etc...

See https://github.com/qmk/qmk_firmware/blob/master/docs/feature_haptic_feedback.md#haptic-key-exclusion for details

If you'd like to override this, you'll need to create a function as follows:
`bool get_haptic_enabled_key_user(uint16_t keycode, keyrecord_t *record)`

In this function, define the key combinations you want to enable, similar to the following example:
```c
bool get_haptic_enabled_key_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ENTER:
            return true;
            break;
        case KC_ESCAPE:
            return true;
            break;
        default:
            break;
    }
    return false;
}
```

## Audio

Enable special audio features. Please see https://github.com/qmk/qmk_firmware/blob/master/docs/feature_audio.md for general audio features that you can enable and use.

Note that the ctrl-X audio responses will use control as the modifier, so it won't work on a Mac by default. However, if are primarily using a Mac, enable the `FP_MAC_PREFERRED` in your config.h

| Setting                                 | Description                                                                     | Default                         |
| --------------------------------------- | ------------------------------------------------------------------------------- | ------------------------------- |
| `FP_AUDIO_MOUSE_BUTTONS`               | (Optional) Enable audio response for Mouse 1, 2, and 3                           | `undefined`                     |
| `FP_AUDIO_CUT_COPY_PASTE`              | (Optional) Enable audio response for ctrl-x, ctrl-c, ctrl-v                      | `undefined`                     |
| `FP_AUDIO_SAVE`                        | (Optional) Enable audio response for ctrl-s                                      | `undefined`                     |


## Keymap

If you are looking to use process_record_kb() or process_record


## Debugging

| Setting                                 | Description                                                                                        | Default                                                                             |
| --------------------------------------- | -------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------- |
| `FP_SR595_MATRIX_DEBUG`                 | (Optional) Enable debugging the 74hc595 shift register code                                        | `undefined`                                                                         |
| `FP_SR595_MATRIX_DEBUG_RATIO`           | (Optional) Frequency for outputting matrix scan information for the shift register (1 in X scans)  | `10000`                                                                             |

## STeMCell v1.0.0

There aren't many of these out there, but if you are running one, you'll need to make the following changes before building:
```
// In platforms/chibios/converters/promicro_to_stemcell/_pin_defs.h
// Add this to the bottom of the file

// SADEK: For STeMCell v1.0.0, need to swap B1 and B2, since the hardware has it swapped
#undef B1
#define B1 PAL_LINE(GPIOA, 7)
#undef B2
#define B2 PAL_LINE(GPIOA, 5)
```

## Appreciation

Thank you:
* Drashna - for the great examples in their userspace implementation.
* Wilbatech - for the example of keyboard agnostic code in QMK.
