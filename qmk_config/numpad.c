#include "numpad.h"

#ifdef LED_MATRIX_ENABLE

#include "is31fl3731-simple.h"

const is31_led g_is31_leds[LED_DRIVER_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  LED address
 *   |  | */
	{0, C1_1},
	{0, C1_2},
	{0, C1_3},
	{0, C1_4},
	{0, C1_5},
	
	{0, C2_1},
	{0, C2_2},
	{0, C2_3},
	{0, C2_4},
	
	{0, C3_1},
	{0, C3_2},
	{0, C3_3},
	{0, C3_4},
	{0, C3_5},
	
	{0, C4_1},
	{0, C4_2},
	{0, C4_3},
	{0, C4_4},
		
	{0, C5_1},
	{0, C5_2},
	{0, C5_3},
	{0, C5_4},
};

void suspend_power_down_kb(void)
{
	led_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_kb(void)
{
	led_matrix_set_suspend_state(false);
}

#endif // LED_MATRIX_ENABLE