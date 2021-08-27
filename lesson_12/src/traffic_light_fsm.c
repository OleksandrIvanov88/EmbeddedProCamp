#include "traffic_light_fsm.h"
#include "lamp_driver.h"
#include <string.h>

typedef enum TLFSM_PHASE
{
    TLFSM_DEFAULT_PHASE,
    TLFSM_PHASE_1,
    TLFSM_PHASE_2,
    TLFSM_PHASE_3,
    TLFSM_PHASE_4_8,
    TLFSM_PHASE_5,
    TLFSM_PHASE_6,
    TLFSM_PHASE_7
}TLFSM_PHASE_E;

typedef struct TLFSM_DATA
{
    TLFSM_PHASE_E activePhase;
    TLFSM_PHASE_E previousPhase;
} TLFSM_DATA_S;

static TLFSM_DATA_S gTlfsmData;

void TLFSM_Init(void)
{
    memset(&gTlfsmData, 0, sizeof(gTlfsmData));
    LDRV_Init();
    LDRV_EwweDontWalkLampOn();
    LDRV_NssnDontWalkLampOn();
    LDRV_EwweRedLampFlashing();
    LDRV_NssnRedLampFlashing();
}

#ifdef TEST
void TLFSM_CorruptState(void)
{
    gTlfsmData.activePhase = ~TLFSM_DEFAULT_PHASE;
}
#endif

void TLFSM_SwitchToNextPhase(void)
{
    switch (gTlfsmData.activePhase)
    {
    case TLFSM_DEFAULT_PHASE: //switch to phase 1
        {
            gTlfsmData.activePhase = TLFSM_PHASE_1;
            gTlfsmData.previousPhase = TLFSM_DEFAULT_PHASE;

            LDRV_NssnRedLampOn();
            LDRV_EwweGreenLampOn();
            LDRV_EwweWalkLampOn();
            break;
        }
    case TLFSM_PHASE_1: //switch to phase 2
        {
            gTlfsmData.activePhase = TLFSM_PHASE_2;
            gTlfsmData.previousPhase = TLFSM_PHASE_1;

            LDRV_EwweDontWalkLampFlashing();
            break;
        } 
    case TLFSM_PHASE_2: //switch to phase 3
        {
            gTlfsmData.activePhase = TLFSM_PHASE_3;
            gTlfsmData.previousPhase = TLFSM_PHASE_2;

            LDRV_EwweDontWalkLampOn();
            LDRV_EwweYellowLampOn();
            break;
        } 
    case TLFSM_PHASE_3://switch to phase 4
        {
            gTlfsmData.activePhase = TLFSM_PHASE_4_8;
            gTlfsmData.previousPhase = TLFSM_PHASE_3;

            LDRV_EwweRedLampOn();
            break;
        } 
    case TLFSM_PHASE_4_8: //switch to phase 1 or phase 5
        {
            if(TLFSM_PHASE_3 == gTlfsmData.previousPhase)
            {
                gTlfsmData.activePhase = TLFSM_PHASE_5;
                
                LDRV_NssnWalkLampOn();
                LDRV_NssnGreenLampOn();

            } else 
            {
                gTlfsmData.activePhase = TLFSM_PHASE_1;
                LDRV_EwweGreenLampOn();
                LDRV_EwweWalkLampOn();
            }
            gTlfsmData.previousPhase = TLFSM_PHASE_4_8;
            break;
        } 
    case TLFSM_PHASE_5: //switch to phase 6
        {
            gTlfsmData.activePhase = TLFSM_PHASE_6;
            gTlfsmData.previousPhase = TLFSM_PHASE_5;

            LDRV_NssnDontWalkLampFlashing();
            break;
        } 
    case TLFSM_PHASE_6: //switch to phase 7
        {
            gTlfsmData.activePhase = TLFSM_PHASE_7;
            gTlfsmData.previousPhase = TLFSM_PHASE_6;

            LDRV_NssnDontWalkLampOn();
            LDRV_NssnYellowLampOn();
            break;
        }
    case TLFSM_PHASE_7: //switch to phase 8
        {
            gTlfsmData.activePhase = TLFSM_PHASE_4_8;
            gTlfsmData.previousPhase = TLFSM_PHASE_7;

            LDRV_NssnRedLampOn();
            break;
        }                                           
    default:
        {
            LDRV_error_handler();
            break;
        }
    }
}


void TLFSM_SwitchToDefaultPhase(void)
{
    gTlfsmData.activePhase = TLFSM_DEFAULT_PHASE;
    gTlfsmData.previousPhase = TLFSM_DEFAULT_PHASE;

    LDRV_EwweDontWalkLampOn();
    LDRV_NssnDontWalkLampOn();

    LDRV_EwweRedLampFlashing();
    LDRV_NssnRedLampFlashing();
}




