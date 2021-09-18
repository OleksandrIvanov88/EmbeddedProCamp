#include "unity.h"
#include "elevator_logic.h"
#include "type.h"
#include "mock_cabin_brake_driver.h"
#include "mock_door_actuator_driver.h"
#include "mock_motor_driver.h"
#include "mock_inputs_driver.h"
#include "mock_error_logic.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/**
 * Given Elevator’s power is off
 * When Elevator’s power is on and initialization occurs 
 * Then Motor, Cabin Brakes, Motor Actuator ans Inputs drivers shall be initialized 
 * And Door shall be closed 
 * Then Cabin brakes shall be off
 * And Motor Low Speed down shall be activated and move to MIN switch
 * Then Motor shall be off
 * And Motor Low Speed Up shall be activated and move to FLOOR switch
 * Then Cabin shall be stoped and door opened
 */
void test_Initialization(void)
{
    //assert
    MDRV_Init_Expect();
    CBDRV_Init_Expect();
    DADRV_Init_Expect();
    INDRV_Init_Expect();
    DADRV_ActuatorsClosening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    DADRV_ActuatorsOff_Expect();
    CBDRV_BrakesOff_Expect();
    MDRV_LowSpeedDown_Expect();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_MAX);
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_MIN);
    MDRV_SpeedOff_Expect();
    MDRV_LowSpeedUp_Expect();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR);
    MDRV_SpeedOff_Expect();
    CBDRV_BrakesOn_Expect();
    DADRV_ActuatorsOpening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DADRV_ActuatorsOff_Expect();
    //act 
    ELFSM_ElvInit();
    TEST_ASSERT_EQUAL_INT( 1, gElv_data.current_floor); 
}

/**
 * Given Elevator’s is initialized
 * When incabin Stop button is be pressed  
 * Then no change in cabin state should happened
 */
void test_Stop_button_presed()
{
    //assert
    INDRV_Keys_ExpectAndReturn(KEY_STOP_CABIN);
    TEST_ASSERT_EQUAL_INT(CABIN_PHASE_STOP, gElv_data.cabin_phase); 
    //act
    ELFSM_ElvCabinSwitchToNextPhase();
}

/**
 * Given Elevator’s is initialized
 * When Keys() return not valid value 
 * Then no change in cabin state should happened
 */
void test_NotValid_button_presed()
{
    //assert
    INDRV_Keys_ExpectAndReturn(-4);
    TEST_ASSERT_EQUAL_INT(CABIN_PHASE_STOP, gElv_data.cabin_phase); 
    //act
    ELFSM_ElvCabinSwitchToNextPhase();
}

/**
 * Given Elevator’s is initialized
 * When Outcabin or incabin button is be pressed  
 * Then door shall be closed 
 * And cabin brakes shall be off
 * Then Low Speed Up shall be activated 
 */
void test_Stop_to_Moving_Up_Low()
{
    //assert
    INDRV_Keys_ExpectAndReturn(KEY_NOT_PRESED);
    INDRV_Keys_ExpectAndReturn(KEY_FLOOR_2_CABIN);
    DADRV_ActuatorsClosening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    DADRV_ActuatorsOff_Expect();
    CBDRV_BrakesOff_Expect();
    MDRV_LowSpeedUp_Expect();
    //act
    ELFSM_ElvCabinSwitchToNextPhase();
}

/**
 * Given Elevator’s is Moving Up Low 
 * When Floor high switch is triggered 
 * Then Fast Speed Up shall be activated  
 */
void test_Moving_Up_Low_to_High()
{
    //assert
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    MDRV_FastSpeedUp_Expect();
    //act
    ELFSM_ElvCabinSwitchToNextPhase();
}

/**
 * Given Elevator’s is Moving Fast Up
 * When Floor low switch is triggered
 * And Next Floor is requested floor
 * Then Low Speed Up shall be activated 
 * And floor switch should be triggered
 */
void test_Moving_Up_High_to_Low()
{
    //assert
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    MDRV_LowSpeedUp_Expect();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR);
    //act
    ELFSM_ElvCabinSwitchToNextPhase();
}

/**
 * Given Elevator’s is Moving Low Up
 * And Floor is requested floor
 * Then Cabin shall be stoped
 */
void test_Moving_Up_Low_to_Stop()
{
    //assert
    MDRV_SpeedOff_Expect();
    CBDRV_BrakesOn_Expect();
    DADRV_ActuatorsOpening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DADRV_ActuatorsOff_Expect();
    //act
    ELFSM_ElvCabinSwitchToNextPhase();
    TEST_ASSERT_EQUAL_INT(2, gElv_data.current_floor); 
}

/**
 * Given Elevator’s is Stoped at 2nd floor
 * When outcabin or incabin button 1st floor pressed  
 * Then door shall be closed 
 * And cabin brakes shall be off
 * Then Low Speed Down shall be activated 
 */
void test_Stop_to_Moving_Down_Low()
{
    //assert
    INDRV_Keys_ExpectAndReturn(KEY_FLOOR_1_CABIN);
    DADRV_ActuatorsClosening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    DADRV_ActuatorsOff_Expect();
    CBDRV_BrakesOff_Expect();
    MDRV_LowSpeedDown_Expect();
    //act
    ELFSM_ElvCabinSwitchToNextPhase();
}

/**
 * Given Elevator’s is Moving Down Low 
 * When Floor low switch is triggered 
 * Then Fast Speed Up shall be activated  
 */
void test_Moving_Down_Low_to_High()
{
    //assert
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    MDRV_FastSpeedDown_Expect();
    //act
    ELFSM_ElvCabinSwitchToNextPhase();
}

/**
 * Given Elevator’s is Moving Fast Down
 * When Floor high switch is triggered
 * And Next Floor is requested floor
 * Then Low Speed Up shall be activated 
 * And Floor switch should be triggered
 */
void test_Moving_Down_High_to_Low()
{
    //assert
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    MDRV_LowSpeedDown_Expect();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR);
    //act
    ELFSM_ElvCabinSwitchToNextPhase();
}

/**
 * Given Elevator’s is Moving Low Down
 * And Floor is requested floor
 * Then Cabin shall be stoped
 */
void test_Moving_Down_Low_to_Stop()
{
    //assert
    MDRV_SpeedOff_Expect();
    CBDRV_BrakesOn_Expect();
    DADRV_ActuatorsOpening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DADRV_ActuatorsOff_Expect();
    //act
    ELFSM_ElvCabinSwitchToNextPhase();
    TEST_ASSERT_EQUAL_INT( 1, gElv_data.current_floor); 
}


/**
 * Given Elevator’s is Stoped at 1st floor
 * When outcabin or incabin button for 3rd floor pressed  
 * Then door shall be closed 
 * And cabin brakes shall be off
 * Then Low Speed Up shall be activated 
 * When Floor high switch is triggered 
 * Then High Speed Up shall be activated 
 * When Floor Low, Floor and Floor high switches are triggered 
 * Then elevator shall keep moving fast
 * When Floor Low switch is triggered
 * Then Low Speed Up shall be activated 
 * When Floor switch is triggered 
 * Then elevator shell be stoped 
 */
void test_Floor1_to_Floor3()
{
    //assert
    TEST_ASSERT_EQUAL_INT(1, gElv_data.current_floor); 
    INDRV_Keys_ExpectAndReturn(KEY_FLOOR_3_CABIN);
    DADRV_ActuatorsClosening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    DADRV_ActuatorsOff_Expect();
    CBDRV_BrakesOff_Expect();
    MDRV_LowSpeedUp_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    MDRV_FastSpeedUp_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    TEST_ASSERT_EQUAL_INT(CABIN_PHASE_MOVING_UP_FAST, gElv_data.cabin_phase);
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR); 
    TEST_ASSERT_EQUAL_INT(CABIN_PHASE_MOVING_UP_FAST, gElv_data.cabin_phase);
    ELFSM_ElvCabinSwitchToNextPhase();
    TEST_ASSERT_EQUAL_INT(2, gElv_data.current_floor); 
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    MDRV_LowSpeedUp_Expect();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR);
    ELFSM_ElvCabinSwitchToNextPhase();
    MDRV_SpeedOff_Expect();
    CBDRV_BrakesOn_Expect();
    DADRV_ActuatorsOpening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DADRV_ActuatorsOff_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    TEST_ASSERT_EQUAL_INT(3, gElv_data.current_floor);  
}


/**
 * Given Elevator’s is Stoped at 3rd floor
 * When outcabin or incabin button for 1st floor pressed  
 * Then door shall be closed 
 * And cabin brakes shall be off
 * Then Low Speed Down shall be activated 
 * When Floor Low switch is triggered 
 * Then High Speed Down shall be activated 
 * When Floor High, Floor and Floor low switches are triggered 
 * Then elevator shall keep moving fast
 * When Floor high switch is triggered
 * Then Low Speed Down shall be activated 
 * When Floor switch is triggered 
 * Then elevator shell be stoped 
 */
void test_Floor3_to_Floor1()
{
    //assert
    TEST_ASSERT_EQUAL_INT(3, gElv_data.current_floor); 
    INDRV_Keys_ExpectAndReturn(KEY_FLOOR_1_CABIN);
    DADRV_ActuatorsClosening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    DADRV_ActuatorsOff_Expect();
    CBDRV_BrakesOff_Expect();
    MDRV_LowSpeedDown_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    MDRV_FastSpeedDown_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    TEST_ASSERT_EQUAL_INT(CABIN_PHASE_MOVING_DOWN_FAST, gElv_data.cabin_phase);
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR); 
    TEST_ASSERT_EQUAL_INT(CABIN_PHASE_MOVING_DOWN_FAST, gElv_data.cabin_phase);
    ELFSM_ElvCabinSwitchToNextPhase();
    TEST_ASSERT_EQUAL_INT(2, gElv_data.current_floor); 
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    MDRV_LowSpeedDown_Expect();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR);
    ELFSM_ElvCabinSwitchToNextPhase();
    MDRV_SpeedOff_Expect();
    CBDRV_BrakesOn_Expect();
    DADRV_ActuatorsOpening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DADRV_ActuatorsOff_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    TEST_ASSERT_EQUAL_INT(1, gElv_data.current_floor);  
}


/**
 * Given Elevator’s is Stoped at 1st floor
 * When incabin button for 3rd floor pressed  
 * Then door shall be closed 
 * And cabin brakes shall be off
 * Then Low Speed Up shall be activated 
 * When Floor high switch is triggered 
 * Then High Speed Up shall be activated 
 * And Stop butten pressed
 * When Floor Low switch is triggered
 * Then Low Speed Up shall be activated 
 * When Floor switch is triggered 
 * Then elevator shell be stoped on 2nd floor 
 */
void test_Floor1_to_Floor3_Stop_on_2_from_high_speed()
{
    //arange
    gElv_data.current_floor = 1;
    //assert
    TEST_ASSERT_EQUAL_INT(1, gElv_data.current_floor); 
    INDRV_Keys_ExpectAndReturn(KEY_FLOOR_3_CABIN);
    DADRV_ActuatorsClosening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    DADRV_ActuatorsOff_Expect();
    CBDRV_BrakesOff_Expect();
    MDRV_LowSpeedUp_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    MDRV_FastSpeedUp_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_NOSIGNAL);
    INDRV_Keys_ExpectAndReturn(KEY_NOT_PRESED);
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_NOSIGNAL);
    INDRV_Keys_ExpectAndReturn(KEY_STOP_CABIN);
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    MDRV_LowSpeedUp_Expect();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR);
    ELFSM_ElvCabinSwitchToNextPhase();
    MDRV_SpeedOff_Expect();
    CBDRV_BrakesOn_Expect();
    DADRV_ActuatorsOpening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DADRV_ActuatorsOff_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    TEST_ASSERT_EQUAL_INT(2, gElv_data.current_floor);  
}


/**
 * Given Elevator’s is Stoped at 3rd floor
 * When incabin button for 1st floor pressed  
 * Then door shall be closed 
 * And cabin brakes shall be off
 * Then Low Speed Down shall be activated 
 * When Floor low switch is triggered 
 * Then High Speed Up shall be activated 
 * And Stop butten pressed
 * When Floor high switch is triggered
 * Then Low Speed Up shall be activated 
 * When Floor switch is triggered 
 * Then elevator shell be stoped on 2nd floor 
 */
void test_Floor3_to_Floor1_Stop_on_2_from_high_speed()
{
    //arange
    gElv_data.current_floor = 3;
    //assert
    TEST_ASSERT_EQUAL_INT(3, gElv_data.current_floor); 
    INDRV_Keys_ExpectAndReturn(KEY_FLOOR_1_CABIN);
    DADRV_ActuatorsClosening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    DADRV_ActuatorsOff_Expect();
    CBDRV_BrakesOff_Expect();
    MDRV_LowSpeedDown_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    MDRV_FastSpeedDown_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_NOSIGNAL);
    INDRV_Keys_ExpectAndReturn(KEY_NOT_PRESED);
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_NOSIGNAL);
    INDRV_Keys_ExpectAndReturn(KEY_STOP_CABIN);
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    MDRV_LowSpeedDown_Expect();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR);
    ELFSM_ElvCabinSwitchToNextPhase();
    MDRV_SpeedOff_Expect();
    CBDRV_BrakesOn_Expect();
    DADRV_ActuatorsOpening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DADRV_ActuatorsOff_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    TEST_ASSERT_EQUAL_INT(2, gElv_data.current_floor);  
}

/**
 * Given Elevator’s is Stoped at 1st floor
 * When incabin button for 3rd floor pressed  
 * Then door shall be closed 
 * And cabin brakes shall be off
 * Then Low Speed Up shall be activated 
 * And Stop butten pressed
 * When Floor high switch is triggered 
 * Then High Speed Up shall be activated 
 * When Floor Low switch is triggered
 * Then Low Speed Up shall be activated 
 * When Floor switch is triggered 
 * Then elevator shell be stoped on 2nd floor 
 */
void test_Floor1_to_Floor3_Stop_on_2_from_low_speed()
{
    //arange
    gElv_data.current_floor = 1;
    //assert
    TEST_ASSERT_EQUAL_INT(1, gElv_data.current_floor); 
    INDRV_Keys_ExpectAndReturn(KEY_FLOOR_3_CABIN);
    DADRV_ActuatorsClosening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    DADRV_ActuatorsOff_Expect();
    CBDRV_BrakesOff_Expect();
    MDRV_LowSpeedUp_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_NOSIGNAL);

    INDRV_Keys_ExpectAndReturn(KEY_NOT_PRESED);
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_NOSIGNAL);

    INDRV_Keys_ExpectAndReturn(KEY_STOP_CABIN);
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    MDRV_FastSpeedUp_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    MDRV_LowSpeedUp_Expect();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR);
    ELFSM_ElvCabinSwitchToNextPhase();
    MDRV_SpeedOff_Expect();
    CBDRV_BrakesOn_Expect();
    DADRV_ActuatorsOpening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DADRV_ActuatorsOff_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    TEST_ASSERT_EQUAL_INT(2, gElv_data.current_floor);  
}

/**
 * Given Elevator’s is Stoped at 3rd floor
 * When incabin button for 1st floor pressed  
 * Then door shall be closed 
 * And cabin brakes shall be off
 * Then Low Speed Down shall be activated 
 * And Stop butten pressed
 * When Floor low switch is triggered 
 * Then High Speed Up shall be activated 
 * When Floor high switch is triggered
 * Then Low Speed Up shall be activated 
 * When Floor switch is triggered 
 * Then elevator shell be stoped on 2nd floor 
 */
void test_Floor3_to_Floor1_Stop_on_2_from_low_speed()
{
    //arange
    gElv_data.current_floor = 3;
    //assert
    TEST_ASSERT_EQUAL_INT(3, gElv_data.current_floor); 
    INDRV_Keys_ExpectAndReturn(KEY_FLOOR_1_CABIN);
    DADRV_ActuatorsClosening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    DADRV_ActuatorsOff_Expect();
    CBDRV_BrakesOff_Expect();
    MDRV_LowSpeedDown_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_NOSIGNAL);
    INDRV_Keys_ExpectAndReturn(KEY_NOT_PRESED);
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_NOSIGNAL);
    INDRV_Keys_ExpectAndReturn(KEY_STOP_CABIN);
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    MDRV_FastSpeedDown_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    MDRV_LowSpeedDown_Expect();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR);
    ELFSM_ElvCabinSwitchToNextPhase();
    MDRV_SpeedOff_Expect();
    CBDRV_BrakesOn_Expect();
    DADRV_ActuatorsOpening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DADRV_ActuatorsOff_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    TEST_ASSERT_EQUAL_INT(2, gElv_data.current_floor);  
}


/**
 * Given Elevator’s is Stoped at 3rd floor
 * When incabin button for 1st floor pressed  
 * Then door shall be closed 
 * And cabin brakes shall be off
 * Then Low Speed Down shall be activated 
 * When Floor Low switch is triggered 
 * Then High Speed Down shall be activated 
 * When Floor High switch is triggered 
 * Then  elevator shall keep moving fast
 * And Stop button is pressed 
 * When Floor switch is triggered 
 * The elevator should reduce the speed and be stoped 
 */
void test_Floor3_to_Floor1_Stop_on_2_from_high_2()
{
    //arange
    gElv_data.current_floor = 3;
    //assert
    TEST_ASSERT_EQUAL_INT(3, gElv_data.current_floor); 
    INDRV_Keys_ExpectAndReturn(KEY_FLOOR_1_CABIN);
    DADRV_ActuatorsClosening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    DADRV_ActuatorsOff_Expect();
    CBDRV_BrakesOff_Expect();
    MDRV_LowSpeedDown_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    MDRV_FastSpeedDown_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_NOSIGNAL);
    INDRV_Keys_ExpectAndReturn(KEY_NOT_PRESED);
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_NOSIGNAL);
    INDRV_Keys_ExpectAndReturn(KEY_STOP_CABIN);
    MDRV_LowSpeedDown_Expect();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR);
    ELFSM_ElvCabinSwitchToNextPhase();
    MDRV_SpeedOff_Expect();
    CBDRV_BrakesOn_Expect();
    DADRV_ActuatorsOpening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DADRV_ActuatorsOff_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    TEST_ASSERT_EQUAL_INT(2, gElv_data.current_floor);  
}


/**
 * Given Elevator’s is Stoped at 1st floor
 * When incabin button for 3rd floor pressed  
 * Then door shall be closed 
 * And cabin brakes shall be off
 * Then Low Speed Up shall be activated 
 * When Floor Low High is triggered 
 * Then High Speed Up shall be activated 
 * When Floor Low switch is triggered 
 * Then  elevator shall keep moving fast
 * And Stop button is pressed 
 * When Floor switch is triggered 
 * The elevator should reduce the speed and be stoped 
 */
void test_Floor1_to_Floor3_Stop_on_2_from_high_2()
{
    //arange
    gElv_data.current_floor = 1;
    //assert
    TEST_ASSERT_EQUAL_INT(1, gElv_data.current_floor); 
    INDRV_Keys_ExpectAndReturn(KEY_FLOOR_3_CABIN);
    DADRV_ActuatorsClosening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    DADRV_ActuatorsOff_Expect();
    CBDRV_BrakesOff_Expect();
    MDRV_LowSpeedUp_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    MDRV_FastSpeedUp_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_NOSIGNAL);
    INDRV_Keys_ExpectAndReturn(KEY_NOT_PRESED);
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_NOSIGNAL);
    INDRV_Keys_ExpectAndReturn(KEY_STOP_CABIN);
    MDRV_LowSpeedUp_Expect();
    INDRV_CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR);
    ELFSM_ElvCabinSwitchToNextPhase();
    MDRV_SpeedOff_Expect();
    CBDRV_BrakesOn_Expect();
    DADRV_ActuatorsOpening_Expect();
    INDRV_DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DADRV_ActuatorsOff_Expect();
    ELFSM_ElvCabinSwitchToNextPhase();
    TEST_ASSERT_EQUAL_INT(2, gElv_data.current_floor);  
}

/**
 * Given Elevator is Initialized
 * When wrong state is set for elevator phase
 * Then Error Handler shall be called
 */
void test_Unknown_Cabin_Phase()
{
    //assert
    gElv_data.cabin_phase = CABIN_PHASE_UNKNOWN;
    ELFSM_ErrorHandler_Expect();
    //act
    ELFSM_ElvCabinSwitchToNextPhase();
}

/**
 * Given Elevator is Initialized
 * When wrong state is set for cabin phase
 * Then Error Handler shall be called
 */
void test_Unknown_Door_Phase()
{
    //assert
    gElv_data.door_phase = DOOR_PHASE_UNKNOWN;
    ELFSM_ErrorHandler_Expect();
    //act
    ELFSM_DoorSwitchToNextPhase();
}

