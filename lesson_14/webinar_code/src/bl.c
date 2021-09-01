#include "h_timer.h"
#include "h_pio.h"
#include "bl.h"
#include "stdint.h"




static uint8_t current_state_index;

static void bl_RotationLeds(void);
static void bl_TimerEventHandler(void);

static void bl_state1(void);
static void bl_state2(void);
static void bl_state3(void);
static void bl_state4(void);

typedef void (*BL_STATE_HANDLER)(void);

static const BL_STATE_HANDLER bl_states[] = {
  bl_state1,
  bl_state2,
  bl_state3,
  bl_state4
};

void BL_Init(void)
{
  current_state_index = 0;
  H_PioInit();
  H_TimInit( bl_TimerEventHandler );    
}

static void bl_TimerEventHandler(void)
{
  bl_RotationLeds();
}

static void bl_RotationLeds(void)
{
  BL_STATE_HANDLER current_state;
  current_state = bl_states[current_state_index++];
  if(0 != current_state)
  {
    current_state();
  } 

  if(current_state_index > 3)
  {
    current_state_index = 0;
  }
}

static void bl_state1(void)
{
  H_PioSwitchBlueLeds();
}

static void bl_state2(void)
{
  H_PioSwitchRedLeds();
}

static void bl_state3(void)
{
  H_PioSwitchOrangeLeds();
}

static void bl_state4(void)
{
  H_PioSwitchGreenLeds();
}

