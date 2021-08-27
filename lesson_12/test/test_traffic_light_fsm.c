
#include "unity.h"
#include "traffic_light_fsm.h"
#include "mock_lamp_driver.h"


void setUp(void)
{
}

void tearDown(void)
{
}

/**
 * Given Traffic Light FSM is not initialized
 * When FSM initialization occurs 
 * Then Lamp Driver shall be initialized 
 * And Red Lamp Flashing mode shall be activated on vehicle lights for both NS-SN and EW-WE directions 
 * And Don't Walk lamp shall be switched on for both NS-SN and EW-WE directions
 */

void test_Initialization(void)
{
    //assert
    LDRV_Init_Expect();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();

    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    //act 
    TLFSM_Init();
}

/**
 * Given Traffic Light FSM is initialized
 * When transition to Phase 1 is triggered  
 * Then Red Lamp shall be switched on for NS-SN directions 
 * And Green Lamp shall be switched on for the EW-WE direction
 * And Walk lamp shall be switched on for EW-WE directions
 */
void test_Init_Phase1(void)
{
    //arrrange 
    LDRV_Init_Expect();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    TLFSM_Init();
    
    //assert
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    //act
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in Phase 1
 * When transition to Phase 2 is triggered  
 * Then Don't Walk lamp flashing mode shall be activated for the EW-WE direction 
 */
void test_Phase1_Phase2(void)
{
    //arrrange 
    LDRV_Init_Expect();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    TLFSM_Init();
    
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    //assert
    LDRV_EwweDontWalkLampFlashing_Expect();

    //act
    TLFSM_SwitchToNextPhase();
}


/**
 * Given Traffic Light FSM is in Phase 2
 * When transition to Phase 3 is triggered  
 * Then Don't Walk lamp shall be activated for the EW-WE direction
 * And Yellow Lamp shall be switched on for EW-WE direction  
 */
void test_Phase2_Phase3()
{
    //arrange 
    LDRV_Init_Expect();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    TLFSM_Init();
    
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();
    TLFSM_SwitchToNextPhase();

    //assert 
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();

    //act
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in Phase 3
 * When transition to Phase 4 is triggered  
 * Then Red Lamp lamp shall be switched on for the EW-WE direction
 */
void test_Phase3_Phase4(void)
{
    //arrange 
    LDRV_Init_Expect();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    TLFSM_Init();
    
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    //assert
    LDRV_EwweRedLampOn_Expect();

    //act
    TLFSM_SwitchToNextPhase();

}

/**
 * Given Traffic Light FSM is in Phase 4
 * When transition to Phase 5 is triggered
 * Then Walk lamp shall be activated for thr NS-SN direction 
 * And Green Lamp lamp shall be switched on for the NS-SN direction
 */
void test_Phase4_Phase5(void)
{
    //arrange 
    LDRV_Init_Expect();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    TLFSM_Init();
    
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweRedLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    //assert
    LDRV_NssnWalkLampOn_Expect();
    LDRV_NssnGreenLampOn_Expect();

    //act
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in Phase 5
 * When transition to Phase 6 is triggered
 * Then Don't Walk lamp flashing mode shall be activated for the NS-SN direction 
 */
void test_Phase5_Phase6(void)
{
    //arrange 
    LDRV_Init_Expect();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    TLFSM_Init();
    
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweRedLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_NssnWalkLampOn_Expect();
    LDRV_NssnGreenLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    //assert
    LDRV_NssnDontWalkLampFlashing_Expect();

    //act
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in Phase 6
 * When transition to Phase 7 is triggered
 * Then Don't Walk lamp shall be switched on for the NS-SN direction 
 * And Yellow Lamp shall be switched on for the NS-SN direction 
 */
void test_Phase6_Phase7(void)
{
    //arrange 
    LDRV_Init_Expect();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    TLFSM_Init();
    
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweRedLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_NssnWalkLampOn_Expect();
    LDRV_NssnGreenLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_NssnDontWalkLampFlashing_Expect();
    TLFSM_SwitchToNextPhase();

    //assert
    LDRV_NssnDontWalkLampOn_Expect();
    LDRV_NssnYellowLampOn_Expect();

    //act
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in Phase 7
 * When transition to Phase 8 is triggered
 * Then Red lamp shall be switched on for the NS-SN direction 
 */
void test_Phase7_Phase8(void)
{ 
    //arrange 
    LDRV_Init_Expect();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    TLFSM_Init();
    
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweRedLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_NssnWalkLampOn_Expect();
    LDRV_NssnGreenLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_NssnDontWalkLampFlashing_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_NssnDontWalkLampOn_Expect();
    LDRV_NssnYellowLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    //assert
    LDRV_NssnRedLampOn_Expect();

    //act
    TLFSM_SwitchToNextPhase();
}


/**
 * Given Traffic Light FSM is in Phase 8
 * When transition to Phase 1 is triggered
 * Then Walk Lamp shall be activated for the EW-WE-SN direction
 * And Green lamp shall be switched on for the EW-WE direction
 */

void test_Phase8_Phase1(void)
{
    
    //arrange 
    LDRV_Init_Expect();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    TLFSM_Init();
    
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampFlashing_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_EwweYellowLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_EwweRedLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_NssnWalkLampOn_Expect();
    LDRV_NssnGreenLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_NssnDontWalkLampFlashing_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_NssnDontWalkLampOn_Expect();
    LDRV_NssnYellowLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    LDRV_NssnRedLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    //assert
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();

    //act
    TLFSM_SwitchToNextPhase();
}

/**
 * Given Traffic Light FSM is in Phase 1
 * When transition to Default Phase is triggered
 * Then Don't walk shall be activated for the EW-WE direction
 * And Don't walk shall be activated for the NS-SN direction 
 * And Red lamp flashing mode shall be activated for the EW-WE direction
 * And Red lamp flashing mode shall be activated for the NS-SN direction
 */

void test_Phase1_Default(void)
{
    //arrange 
    LDRV_Init_Expect();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    TLFSM_Init();
    
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    //assert
    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();

    //act
    TLFSM_SwitchToDefaultPhase();
}

/**
 * Given Traffic Light FSM is in Phase 1
 * When active phase to not valid value
 * Then errro handler shall be called 
 */
void test_CorruptState(void)
{
    //arrrange 
    LDRV_Init_Expect();

    LDRV_EwweDontWalkLampOn_Expect();
    LDRV_NssnDontWalkLampOn_Expect();
    LDRV_EwweRedLampFlashing_Expect();
    LDRV_NssnRedLampFlashing_Expect();
    TLFSM_Init();
    
    LDRV_NssnRedLampOn_Expect();
    LDRV_EwweGreenLampOn_Expect();
    LDRV_EwweWalkLampOn_Expect();
    TLFSM_SwitchToNextPhase();

    //assert
   LDRV_error_handler_Expect();

    //act
    TLFSM_CorruptState();
    TLFSM_SwitchToNextPhase();
}