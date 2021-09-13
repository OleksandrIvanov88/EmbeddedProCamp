#ifndef _TYPE_H_
#define _TYPE_H_
#include <stdint.h>

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
    DOOR_PHASE_OPEN,
} DOOR_PHASE_E;

typedef struct
{
    int req_floor; 
    uint8_t current_floor;
    ELV_CABIN_PHASE_E cabin_phase;
    DOOR_PHASE_E door_phase;
} ELV_DATA_S;


#endif//_TYPE_H_