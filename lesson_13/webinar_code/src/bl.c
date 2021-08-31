#include "h_timer.h"
#include "h_pio.h"
#include "bl.h"
#include "stdint.h"




static uint8_t timer_counter;

static void bl_RotationLeds(void);
static void bl_TimerEventHandler(void);


#ifdef TEST
void bl_CorruptState(void)
{
    timer_counter = 4;
}
#endif

void BL_Init(void)
{
  timer_counter = 0;
  H_PioInit();
  H_TimInit( bl_TimerEventHandler );    
}


static void bl_TimerEventHandler(void)
{
  bl_RotationLeds();
}

static void bl_RotationLeds(void)
{
  
  switch (timer_counter)
  {
    case 0:
      H_PioSwitchBlueLeds();
      break;
    case 1:
      H_PioSwitchRedLeds();
      break;
    case 2:
      H_PioSwitchOrangeLeds();
      break;
    case 3:
      H_PioSwitchGreenLeds();
      break;
    default:
      H_PioErrorHandler();
      break;  
  }
    
  if (timer_counter<3) timer_counter++;
  else timer_counter=0;
}
