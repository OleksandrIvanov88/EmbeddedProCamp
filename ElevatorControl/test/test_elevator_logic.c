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
    MotorInit_Expect();
    CabinBrakesInit_Expect();
    DoorActuatorInit_Expect();
    InputsInit_Expect();
    DoorActuatorsClosening_Expect();
    DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    DoorActuatorsOff_Expect();
    CabinBrakesOff_Expect();
    MotorLowSpeedDown_Expect();
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_MAX);
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_MIN);
    MotorSpeedOff_Expect();
    MotorLowSpeedUp_Expect();
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR);
    MotorSpeedOff_Expect();
    CabinBrakesOn_Expect();
    DoorActuatorsOpening_Expect();
    DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DoorActuatorsOff_Expect();
    //act 
    ElvInit();
    TEST_ASSERT_EQUAL_INT( 1, gElv_data.current_floor); 
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
    Keys_ExpectAndReturn(KEY_FLOOR_CABIN_NOT_PRESED);
    Keys_ExpectAndReturn(KEY_FLOOR_2_CABIN);
    DoorActuatorsClosening_Expect();
    DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    DoorActuatorsOff_Expect();
    CabinBrakesOff_Expect();
    MotorLowSpeedUp_Expect();
    //act
    ElvCabinSwitchToNextPhase();
}

/**
 * Given Elevator’s is Moving Up Low 
 * When Floor high switch is triggered 
 * Then Fast Speed Up shall be activated  
 */
void test_Moving_Up_Low_to_High()
{
    //assert
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    MotorFastSpeedUp_Expect();
    //act
    ElvCabinSwitchToNextPhase();
}

/**
 * Given Elevator’s is Moving Fast Up
 * When Floor low switch is triggered
 * And Next Floor is requested floor
 * Then Low Speed Up shall be activated 
 */
void test_Moving_Up_High_to_Low()
{
    //assert
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    MotorLowSpeedUp_Expect();
    //act
    ElvCabinSwitchToNextPhase();
}

/**
 * Given Elevator’s is Moving Low Up
 * And Floor is requested floor
 * Then Cabin shall be stoped
 */
void test_Moving_Up_Low_to_Stop()
{
    //assert
    MotorSpeedOff_Expect();
    CabinBrakesOn_Expect();
    DoorActuatorsOpening_Expect();
    DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DoorActuatorsOff_Expect();
    //act
    ElvCabinSwitchToNextPhase();
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
    Keys_ExpectAndReturn(KEY_FLOOR_1_CABIN);
    DoorActuatorsClosening_Expect();
    DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    DoorActuatorsOff_Expect();
    CabinBrakesOff_Expect();
    MotorLowSpeedDown_Expect();
    //act
    ElvCabinSwitchToNextPhase();
}

/**
 * Given Elevator’s is Moving Down Low 
 * When Floor low switch is triggered 
 * Then Fast Speed Up shall be activated  
 */
void test_Moving_Down_Low_to_High()
{
    //assert
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    MotorFastSpeedDown_Expect();
    //act
    ElvCabinSwitchToNextPhase();
}

/**
 * Given Elevator’s is Moving Fast Down
 * When Floor high switch is triggered
 * And Next Floor is requested floor
 * Then Low Speed Up shall be activated 
 */
void test_Moving_Down_High_to_Low()
{
    //assert
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    MotorLowSpeedDown_Expect();
    //act
    ElvCabinSwitchToNextPhase();
}

/**
 * Given Elevator’s is Moving Low Down
 * And Floor is requested floor
 * Then Cabin shall be stoped
 */
void test_Moving_Down_Low_to_Stop()
{
    //assert
    MotorSpeedOff_Expect();
    CabinBrakesOn_Expect();
    DoorActuatorsOpening_Expect();
    DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DoorActuatorsOff_Expect();
    //act
    ElvCabinSwitchToNextPhase();
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
    Keys_ExpectAndReturn(KEY_FLOOR_3_CABIN);
    DoorActuatorsClosening_Expect();
    DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    DoorActuatorsOff_Expect();
    CabinBrakesOff_Expect();
    MotorLowSpeedUp_Expect();
    ElvCabinSwitchToNextPhase();
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    MotorFastSpeedUp_Expect();
    ElvCabinSwitchToNextPhase();
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    TEST_ASSERT_EQUAL_INT(CABIN_PHASE_MOVING_UP_FAST, gElv_data.cabin_phase);
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR); 
    TEST_ASSERT_EQUAL_INT(CABIN_PHASE_MOVING_UP_FAST, gElv_data.cabin_phase);
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    TEST_ASSERT_EQUAL_INT(CABIN_PHASE_MOVING_UP_FAST, gElv_data.cabin_phase);
    ElvCabinSwitchToNextPhase();
    TEST_ASSERT_EQUAL_INT(2, gElv_data.current_floor); 
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    MotorLowSpeedUp_Expect();
    ElvCabinSwitchToNextPhase();
    MotorSpeedOff_Expect();
    CabinBrakesOn_Expect();
    DoorActuatorsOpening_Expect();
    DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DoorActuatorsOff_Expect();
    ElvCabinSwitchToNextPhase();
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
    Keys_ExpectAndReturn(KEY_FLOOR_1_CABIN);
    DoorActuatorsClosening_Expect();
    DoorSwitches_ExpectAndReturn(DOOR_SWITCH_CLOSED);
    DoorActuatorsOff_Expect();
    CabinBrakesOff_Expect();
    MotorLowSpeedDown_Expect();
    ElvCabinSwitchToNextPhase();
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    MotorFastSpeedDown_Expect();
    ElvCabinSwitchToNextPhase();
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    TEST_ASSERT_EQUAL_INT(CABIN_PHASE_MOVING_DOWN_FAST, gElv_data.cabin_phase);
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR); 
    TEST_ASSERT_EQUAL_INT(CABIN_PHASE_MOVING_DOWN_FAST, gElv_data.cabin_phase);
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_LOW);
    TEST_ASSERT_EQUAL_INT(CABIN_PHASE_MOVING_DOWN_FAST, gElv_data.cabin_phase);
    ElvCabinSwitchToNextPhase();
    TEST_ASSERT_EQUAL_INT(2, gElv_data.current_floor); 
    CabinSwitches_ExpectAndReturn(CABIN_SWITCH_FLOOR_HIGH);
    MotorLowSpeedDown_Expect();
    ElvCabinSwitchToNextPhase();
    MotorSpeedOff_Expect();
    CabinBrakesOn_Expect();
    DoorActuatorsOpening_Expect();
    DoorSwitches_ExpectAndReturn(DOOR_SWITCH_OPENED);
    DoorActuatorsOff_Expect();
    ElvCabinSwitchToNextPhase();
    TEST_ASSERT_EQUAL_INT(1, gElv_data.current_floor);  
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
    ErrorHandler_Expect();
    //act
    ElvCabinSwitchToNextPhase();
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
    ErrorHandler_Expect();
    //act
     DoorSwitchToNextPhase();
}

