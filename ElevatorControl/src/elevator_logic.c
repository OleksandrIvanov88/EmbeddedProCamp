#include "type.h"
#include "elevator_logic.h"
#include "door_actuator_driver.h"
#include "cabin_brake_driver.h"
#include "motor_driver.h"
#include "inputs_driver.h"
#include "error_logic.h"
#include <string.h>
#include <stdlib.h>



#ifdef TEST
ELV_DATA_S gElv_data;
#else
static ELV_DATA_S gElv_data;
#endif


static void activate_stope_phase(void)
{
    MotorSpeedOff();
    CabinBrakesOn();
    DoorSwitchToNextPhase();
    gElv_data.cabin_phase = CABIN_PHASE_STOP;
}


void ElvInit(void)
{
    memset(&gElv_data, 0, sizeof(gElv_data));
    MotorInit();
    CabinBrakesInit();
    DoorActuatorInit();
    InputsInit();
    DoorActuatorsClosening();
    while (DOOR_SWITCH_CLOSED != DoorSwitches());
    DoorActuatorsOff();
    gElv_data.door_phase = DOOR_PHASE_CLOSE;
    CabinBrakesOff();
    MotorLowSpeedDown();
    while(CABIN_SWITCH_MIN != CabinSwitches());
    MotorSpeedOff();
    MotorLowSpeedUp();
    while (CABIN_SWITCH_FLOOR != CabinSwitches());
    activate_stope_phase();
    gElv_data.current_floor = 1;
}

void DoorSwitchToNextPhase(void)
{
    switch(gElv_data.door_phase)
    {
        case DOOR_PHASE_CLOSE: //switch to phase Open
            {
                DoorActuatorsOpening();
                while(DOOR_SWITCH_OPENED != DoorSwitches());
                DoorActuatorsOff();
                gElv_data.door_phase = DOOR_PHASE_OPEN;
                break;
            }
        case DOOR_PHASE_OPEN: //switch to phase Close
            {
                DoorActuatorsClosening();
                while (DOOR_SWITCH_CLOSED != DoorSwitches());
                DoorActuatorsOff();
                gElv_data.door_phase = DOOR_PHASE_CLOSE;
                break;
            }      
        default:
            {
                ErrorHandler();
                break;
            }    
    }

}

void ElvCabinSwitchToNextPhase(void)
{
    switch(gElv_data.cabin_phase)
    {
        case CABIN_PHASE_STOP: //switch to phase Moving Up Slowly or Moving Down Slowly or stay with Stop phase
            {
                while (KEY_FLOOR_CABIN_NOT_PRESED == (gElv_data.req_floor =  Keys()));
                if(gElv_data.req_floor >= KEY_FLOOR_3_OUT 
                    && gElv_data.req_floor <= KEY_STOP_CABIN)
                {
                    if(abs(gElv_data.req_floor) > gElv_data.current_floor
                            && gElv_data.req_floor != KEY_STOP_CABIN)
                    {
                        if(DOOR_PHASE_OPEN == gElv_data.door_phase)
                        {
                            DoorSwitchToNextPhase();
                        }
                        CabinBrakesOff();
                        MotorLowSpeedUp();
                        gElv_data.cabin_phase = CABIN_PHASE_MOVING_UP_SLOW;
                    } else if(abs(gElv_data.req_floor) < gElv_data.current_floor)
                    {
                        if(DOOR_PHASE_OPEN == gElv_data.door_phase)
                        {
                            DoorSwitchToNextPhase();
                        }
                        CabinBrakesOff();
                        MotorLowSpeedDown();
                        gElv_data.cabin_phase = CABIN_PHASE_MOVING_DOWN_SLOW;
                    }
                }    
                break;
            }
        case CABIN_PHASE_MOVING_UP_SLOW://switch to phase Moving Up Fast or Stop
            {
               
                if(gElv_data.current_floor == abs(gElv_data.req_floor))
                {
                    activate_stope_phase();
                    gElv_data.cabin_phase = CABIN_PHASE_STOP;
                } else 
                {
                    while (CABIN_SWITCH_FLOOR_HIGH != CabinSwitches());
                    MotorFastSpeedUp();
                    gElv_data.cabin_phase = CABIN_PHASE_MOVING_UP_FAST;
                }
                break;
            }
        case CABIN_PHASE_MOVING_DOWN_SLOW://switch to phase Moving Down Fast or Stop
            {
                if(gElv_data.current_floor == abs(gElv_data.req_floor))
                {
                    activate_stope_phase();
           
                }else 
                {
                    while (CABIN_SWITCH_FLOOR_LOW != CabinSwitches());
                    MotorFastSpeedDown();
                    gElv_data.cabin_phase = CABIN_PHASE_MOVING_DOWN_FAST;
                }    
                break;
            }
        case CABIN_PHASE_MOVING_UP_FAST://switch to phase Moving UP Slowly or stay with phase Moving Up fast
            {
               
                while (CABIN_SWITCH_FLOOR_LOW != CabinSwitches());
                if(1 == abs(gElv_data.req_floor) - gElv_data.current_floor)
                {
                    MotorLowSpeedUp();
                    gElv_data.cabin_phase = CABIN_PHASE_MOVING_UP_SLOW;
                    ++gElv_data.current_floor;
                } else 
                {
                    while (CABIN_SWITCH_FLOOR != CabinSwitches());
                    ++gElv_data.current_floor;
                }
                break;
            }
        case CABIN_PHASE_MOVING_DOWN_FAST://switch to phase Moving Down Slowly or stay with phase Moving Down Fast
            {
                while (CABIN_SWITCH_FLOOR_HIGH != CabinSwitches());
                if(1 == gElv_data.current_floor - abs(gElv_data.req_floor))
                {
                    MotorLowSpeedDown();
                    gElv_data.cabin_phase = CABIN_PHASE_MOVING_DOWN_SLOW;
                    --gElv_data.current_floor;
                } else 
                {
                    while (CABIN_SWITCH_FLOOR != CabinSwitches());
                    --gElv_data.current_floor;
                }
                break;
            }         
        default:
            {
                ErrorHandler();
                break;
            }        
    }
}


