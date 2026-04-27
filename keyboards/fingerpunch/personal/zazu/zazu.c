#include "quantum.h"
#include "zazu.h"
// SADEK: DISPLAY: COMMENT OUT FOR NOW
// #include "display.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    {     40,     39,     38,     37,      5,      4,      3,      2 },
    {     33,     34,     35,     36,      6,      7,      8,      9 },
    {     29,     28,     27,     26,     16,     15,     14,      13 },
    {     41,     32,     25,     24,     18,     17,     10,      1 },
    { NO_LED, NO_LED, NO_LED,     22,     21,     20, NO_LED, NO_LED },
    { NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
    {     42,     31,     30,     23,     19,     12,     11,      0 }
}, {
{3  ,3 },{19 ,0 },{41 ,0 },{59 ,1 },{71 ,10},{84 ,16},{78 ,26},{64 ,20},
{53 ,11},{34 ,9 },{15 ,11},{0  ,13},{12 ,21},{29 ,20},{46 ,21},{57 ,30},
{70 ,36},{50 ,40},{63 ,46},{76 ,52},{95 ,63},{111,63},{127,63},{145,52},
{158,46},{172,40},{152,36},{164,30},{176,21},{192,20},{209,21},{222,13},
{205,11},{186,9 },{168,11},
{157,20},{144,26},{137,16},{151,10},{162,1 },{180,0 },{201,0 },{218,3 }
}, {
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
       4, 4, 4, 4, 4,
             1, 1, 1,
             1, 1, 1,
             1, 1, 1,
    4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4,
       4, 4, 4, 4, 4,
} };
#endif

// SADEK: DISPLAY: COMMENT OUT FOR NOW
// #include "qp.h"
// #include "qp_lvgl.h"

// kb_runtime_config kb_state;

// static painter_device_t display;

// /* void kb_state_update(void) { */
// /*     if (is_keyboard_master()) { */
// /*         // Modify allowed current limits */
// /*         // Turn off the LCD if there's been no matrix activity */
// /*         kb_state.lcd_power = (last_input_activity_elapsed() < 30000) ? 1 : 0; */
// /*     } */
// /* } */

// void keyboard_post_init_user(void) {
//   /* debug_enable=true; */
//   /* debug_matrix=false; */
//   /* debug_keyboard=false; */
//   /* debug_mouse=true; */

//   /* gpio_set_pin_output(LCD_POWER_ENABLE_PIN); */
//   /* gpio_write_pin_high(LCD_POWER_ENABLE_PIN); */
//   display = qp_st7789_make_spi_device(320, 172, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 8, 3);
//   qp_set_viewport_offsets(display, 0, 34);
//   qp_init(display, QP_ROTATION_90); // Initialise the display
//   qp_power(display, true);
//   qp_rect(display, 0, 0, 319, 171, 0, 0, 0, true);

//   if (qp_lvgl_attach(display)) {     // Attach LVGL to the display
//     wait_ms(50);
//     display_init();
//   }
// }

// void housekeeping_task_user(void) {
//   /* kb_state_update(); */
//   /* if (kb_state.lcd_power) { */
//   /*     backlight_level_noeeprom(3); */
//   /*     rgb_matrix_enable_noeeprom(); */
//   /*   } else { */
//   /*     backlight_level_noeeprom(0); */
//   /*     rgb_matrix_disable_noeeprom(); */
//   /*   } */
//   /* static bool lcd_on = false; */
//   /* if (lcd_on != (bool)kb_state.lcd_power) { */
//   /*     lcd_on = (bool)kb_state.lcd_power; */
//   /*     qp_power(display, lcd_on); */
//   /* } */
//   lvgl_event_triggers();
// }

// void board_init(void) {}
