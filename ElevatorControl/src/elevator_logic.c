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
ELFSM_DATA_S gElv_data;
#else
static ELFSM_DATA_S gElv_data;
#endif

static void activate_stope_phase(void)
{
    MDRV_SpeedOff();
    CBDRV_BrakesOn();
    ELFSM_DoorSwitchToNextPhase();
    gElv_data.cabin_phase = CABIN_PHASE_STOP;
}

void ELFSM_ElvInit(void)
{
    
    MDRV_Init();
    CBDRV_Init();
    DADRV_Init();
    INDRV_Init();
    DADRV_ActuatorsClosening();
    memset(&gElv_data, 0, sizeof(gElv_data));
    while (DOOR_SWITCH_CLOSED != INDRV_DoorSwitches());
    DADRV_ActuatorsOff();
    gElv_data.door_phase = DOOR_PHASE_CLOSE;
    CBDRV_BrakesOff();
    MDRV_LowSpeedDown();
    while(CABIN_SWITCH_MIN != INDRV_CabinSwitches());
    MDRV_SpeedOff();
    MDRV_LowSpeedUp();
    while (CABIN_SWITCH_FLOOR != INDRV_CabinSwitches());
    activate_stope_phase();
    gElv_data.current_floor = 1;
}

void ELFSM_DoorSwitchToNextPhase(void)
{
    switch(gElv_data.door_phase)
    {
        case DOOR_PHASE_CLOSE: //switch to phase Open
            {
                DADRV_ActuatorsOpening();
                while(DOOR_SWITCH_OPENED != INDRV_DoorSwitches());
                DADRV_ActuatorsOff();
                gElv_data.door_phase = DOOR_PHASE_OPEN;
                break;
            }
        case DOOR_PHASE_OPEN: //switch to phase Close
            {
                DADRV_ActuatorsClosening();
                while (DOOR_SWITCH_CLOSED != INDRV_DoorSwitches());
                DADRV_ActuatorsOff();
                gElv_data.door_phase = DOOR_PHASE_CLOSE;
                break;
            }      
        default:
            {
                ELFSM_ErrorHandler();
                break;
            }    
    }

}

void ELFSM_ElvCabinSwitchToNextPhase(void)
{
    switch(gElv_data.cabin_phase)
    {
        case CABIN_PHASE_STOP: //switch to phase Moving Up Slowly or Moving Down Slowly or stay with Stop phase
            {
                while (KEY_NOT_PRESED == (gElv_data.req_floor =  INDRV_Keys()));
                if(gElv_data.req_floor >= KEY_STOP_CABIN || gElv_data.req_floor < KEY_FLOOR_3_OUT)
                {
                   gElv_data.cabin_phase = CABIN_PHASE_STOP;
                } else if(abs(gElv_data.req_floor) > gElv_data.current_floor)
                {
                    ELFSM_DoorSwitchToNextPhase();
                    CBDRV_BrakesOff();
                    MDRV_LowSpeedUp();
                    gElv_data.cabin_phase = CABIN_PHASE_MOVING_UP_SLOW;
                } else //if (abs(gElv_data.req_floor) < gElv_data.current_floor)
                {
                    ELFSM_DoorSwitchToNextPhase();
                    CBDRV_BrakesOff();
                    MDRV_LowSpeedDown();
                    gElv_data.cabin_phase = CABIN_PHASE_MOVING_DOWN_SLOW;
                }  
                break;
            }
        case CABIN_PHASE_MOVING_UP_SLOW://switch to phase Moving Up Fast or Stop
            {
               
                if(gElv_data.current_floor == abs(gElv_data.req_floor) || gElv_data.stop_is_pressed)
                {
                    activate_stope_phase();
                    gElv_data.stop_is_pressed = 0;
                    gElv_data.cabin_phase = CABIN_PHASE_STOP;
                } else 
                {
                    while (CABIN_SWITCH_FLOOR_HIGH != INDRV_CabinSwitches())
                    {
                        if(KEY_STOP_CABIN == INDRV_Keys())
                        {
                            gElv_data.stop_is_pressed = 1;
                        }
                    }
                    MDRV_FastSpeedUp();
                    gElv_data.cabin_phase = CABIN_PHASE_MOVING_UP_FAST;
               
                }
                break;
            }
        case CABIN_PHASE_MOVING_DOWN_SLOW://switch to phase Moving Down Fast or Stop
            {
                if(gElv_data.current_floor == abs(gElv_data.req_floor) || gElv_data.stop_is_pressed)
                {
                    activate_stope_phase();
                    gElv_data.stop_is_pressed = 0;
                    gElv_data.cabin_phase = CABIN_PHASE_STOP;
           
                }else 
                {
                    while (CABIN_SWITCH_FLOOR_LOW != INDRV_CabinSwitches())
                    {
                        if(KEY_STOP_CABIN == INDRV_Keys())
                        {
                            gElv_data.stop_is_pressed = 1;
                        }
                    }
                    MDRV_FastSpeedDown();
                    gElv_data.cabin_phase = CABIN_PHASE_MOVING_DOWN_FAST;
                }    
                break;
            }
        case CABIN_PHASE_MOVING_UP_FAST://switch to phase Moving UP Slowly or stay with phase Moving Up fast
            {
                while (CABIN_SWITCH_FLOOR_LOW != INDRV_CabinSwitches())
                {
                    if(KEY_STOP_CABIN == INDRV_Keys())
                    {
                        gElv_data.stop_is_pressed = 1;
                    }
                }

                if(1 == abs(gElv_data.req_floor) - gElv_data.current_floor || gElv_data.stop_is_pressed)
                {
                    MDRV_LowSpeedUp();
                    gElv_data.cabin_phase = CABIN_PHASE_MOVING_UP_SLOW;
                } 

                while (CABIN_SWITCH_FLOOR != INDRV_CabinSwitches())
                {
                    if(KEY_STOP_CABIN == INDRV_Keys())
                    {
                        MDRV_LowSpeedUp();
                        gElv_data.cabin_phase = CABIN_PHASE_MOVING_UP_SLOW;
                        gElv_data.stop_is_pressed = 1;
                    }
                }
                ++gElv_data.current_floor;
                break;
            }
        case CABIN_PHASE_MOVING_DOWN_FAST://switch to phase Moving Down Slowly or stay with phase Moving Down Fast
            {
                while (CABIN_SWITCH_FLOOR_HIGH != INDRV_CabinSwitches())
                {
                     if(KEY_STOP_CABIN == INDRV_Keys())
                    {
                        gElv_data.stop_is_pressed = 1;
                    }
                }

                if(1 == gElv_data.current_floor - abs(gElv_data.req_floor) || gElv_data.stop_is_pressed)
                {
                    MDRV_LowSpeedDown();
                    gElv_data.cabin_phase = CABIN_PHASE_MOVING_DOWN_SLOW;
                } 

                while (CABIN_SWITCH_FLOOR != INDRV_CabinSwitches())
                {
                    if(KEY_STOP_CABIN == INDRV_Keys())
                    {
                        MDRV_LowSpeedDown();
                        gElv_data.cabin_phase = CABIN_PHASE_MOVING_DOWN_SLOW;
                        gElv_data.stop_is_pressed = 1;
                    }
                }
                --gElv_data.current_floor;
                break;
            }         
        default:
            {
                ELFSM_ErrorHandler();
                break;
            }        
    }
}


