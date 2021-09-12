#ifndef _TYPE_H_
#define _TYPE_H_
#include <stdint.h>

// typedef enum
// {
//     SWITCH_OFF,
//     SWITCH_ON
// }SWITCH_STATE_E;

typedef enum 
{
    CABIN_SWITCH_UNKNOWN,
    CABIN_SWITCH_MIN,
    CABIN_SWITCH_FLOOR_HIGH,
    CABIN_SWITCH_FLOOR,
    CABIN_SWITCH_FLOOR_LOW,
    CABIN_SWITCH_MAX
}L_SWITCH_CABIN_E;

typedef enum
{
    DOOR_SWITCH_UNKNOWN,
    DOOR_SWITCH_CLOSED,
    DOOR_SWITCH_OPENED
}L_SWITCH_DOOR_E; 

typedef enum
{
    KEY_FLOOR_3_OUT = -3,
    KEY_FLOOR_2_OUT,
    KEY_FLOOR_1_OUT,
    KEY_FLOOR_CABIN_NOT_PRESED,
    KEY_FLOOR_1_CABIN,
    KEY_FLOOR_2_CABIN,
    KEY_FLOOR_3_CABIN,
    KEY_STOP_CABIN
} KEYS_E;

typedef enum
{   
    CABIN_PHASE_STOP,
    CABIN_PHASE_MOVING_UP_SLOW,
    CABIN_PHASE_MOVING_UP_FAST,
    CABIN_PHASE_MOVING_DOWN_SLOW,
    CABIN_PHASE_MOVING_DOWN_FAST
} ELV_CABIN_PHASE_E;

typedef enum
{
    DOOR_PHASE_CLOSE,
    //DOOR_PHASE_OPENING,
    DOOR_PHASE_OPEN,
    //DOOR_PHASE_CLOSENING
} DOOR_PHASE_E;

// typedef enum
// {
//     POWER_OFF,
//     POWER_ON
// } POWER_E;


typedef struct
{
    uint8_t current_floor;
    //POWER_E power;
    ELV_CABIN_PHASE_E cabin_phase;
    DOOR_PHASE_E door_phase;
    int req_floor; 
    // L_SWITCH_CABIN_E cabin_switch;
    // L_SWITCH_DOOR_E  door_switch;
    //KEYS_E key;
} ELV_DATA_S;


#endif//_TYPE_H_