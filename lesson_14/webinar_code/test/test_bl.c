#include "unity.h"
#include "bl.h"
#include "mock_h_pio.h"
#include "mock_h_timer.h"

static H_TIMER_CB ut_callback;
static void ut_H_TimInit_callback(H_TIMER_CB callback, int cmock_num_calls)
{
    ut_callback = callback;
}

void setUp(void)
{
    H_PioInit_Expect();
    H_TimInit_StubWithCallback(ut_H_TimInit_callback);
    BL_Init();
}

void tearDown(void)
{
}

/**
 * Given bl unit is not initialized
 * When bl initialization occurs 
 * Then pio unit shall be initialized 
 * And timer shall be initialized
 */
void test_bl_init(void)
{
    //assert
    H_PioInit_Expect();
    H_TimInit_StubWithCallback(ut_H_TimInit_callback);
    //act
    BL_Init();
}

/**
 * Given bl unit is initialized
 * When first interrupt occurs 
 * Then blues led shall be activated
 */
void test_bl_blue_led_on(void)
{
    //assert
    H_PioSwitchBlueLeds_Expect();
    //act
    ut_callback();
}

/**
 * Given bl unit is initialized
 * When second interrupt occurs 
 * Then red led shall be activated
 */
void test_bl_red_led_on(void)
{
    //arrange
    H_PioSwitchBlueLeds_Expect();
    ut_callback();

    //assert
    H_PioSwitchRedLeds_Expect();
    //act
    ut_callback();
}

/**
 * Given bl unit is initialized
 * When third interrupt occurs 
 * Then orange led shall be activated
 */
void test_bl_orange_led_on(void)
{
    //arrange
    H_PioSwitchBlueLeds_Expect();
    ut_callback();
    H_PioSwitchRedLeds_Expect();
    ut_callback();

    //assert
    H_PioSwitchOrangeLeds_Expect();
    //act
    ut_callback();
}

/**
 * Given bl unit is initialized
 * When fourth interrupt occurs 
 * Then gree led shall be activated
 */
void test_bl_green_led_on(void)
{
    //arrange
    H_PioSwitchBlueLeds_Expect();
    ut_callback();
    H_PioSwitchRedLeds_Expect();
    ut_callback();
    H_PioSwitchOrangeLeds_Expect();
    ut_callback();
    //assert
    H_PioSwitchGreenLeds_Expect();
    //act
    ut_callback();
}

/**
 * Given bl unit is initialized
 * When fifth interrupt occurs 
 * Then blue led shall be activated 
 */
void test_bl_again_blue_led_on(void)
{
    //arrange
    H_PioSwitchBlueLeds_Expect();
    ut_callback();
    H_PioSwitchRedLeds_Expect();
    ut_callback();
    H_PioSwitchOrangeLeds_Expect();
    ut_callback();
    H_PioSwitchGreenLeds_Expect();
    ut_callback();
    //assert 
    H_PioSwitchBlueLeds_Expect();
    //act
    ut_callback();
}


