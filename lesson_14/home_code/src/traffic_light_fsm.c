#include "traffic_light_fsm.h"
#include "lamp_driver.h"
#include <string.h>
#include <stdint.h>

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

void TLFSM_SwitchToPhase1(void);
void TLFSM_SwitchToPhase2(void);
void TLFSM_SwitchToPhase3(void);
void TLFSM_SwitchToPhase4(void);
void TLFSM_SwitchToPhase_1_or_5(void);
void TLFSM_SwitchToPhase6(void);
void TLFSM_SwitchToPhase7(void);
void TLFSM_SwitchToPhase8(void);

typedef void(*TLFSM_PHASE_SWITCH_HANDLER)(void);

static const TLFSM_PHASE_SWITCH_HANDLER TLFSM_switch_phase[] = {
    TLFSM_SwitchToPhase1,
    TLFSM_SwitchToPhase2,
    TLFSM_SwitchToPhase3,
    TLFSM_SwitchToPhase4,
    TLFSM_SwitchToPhase_1_or_5,
    TLFSM_SwitchToPhase6,
    TLFSM_SwitchToPhase7,
    TLFSM_SwitchToPhase8
};



void TLFSM_Init(void)
{
    memset(&gTlfsmData, 0, sizeof(gTlfsmData));
    LDRV_Init();
    LDRV_EwweDontWalkLampOn();
    LDRV_NssnDontWalkLampOn();
    LDRV_EwweRedLampFlashing();
    LDRV_NssnRedLampFlashing();
}


void TLFSM_SwitchToNextPhase(void)
{

    TLFSM_PHASE_SWITCH_HANDLER switch_state = TLFSM_switch_phase[gTlfsmData.activePhase];
    if(NULL != switch_state)
    {
        switch_state();
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

void TLFSM_SwitchToPhase1(void)
{
    gTlfsmData.activePhase = TLFSM_PHASE_1;
    gTlfsmData.previousPhase = TLFSM_DEFAULT_PHASE;

    LDRV_NssnRedLampOn();
    LDRV_EwweGreenLampOn();
    LDRV_EwweWalkLampOn();
}

void TLFSM_SwitchToPhase2(void)
{
    gTlfsmData.activePhase = TLFSM_PHASE_2;
    gTlfsmData.previousPhase = TLFSM_PHASE_1;

    LDRV_EwweDontWalkLampFlashing();
}

void TLFSM_SwitchToPhase3(void)
{
    gTlfsmData.activePhase = TLFSM_PHASE_3;
    gTlfsmData.previousPhase = TLFSM_PHASE_2;

    LDRV_EwweDontWalkLampOn();
    LDRV_EwweYellowLampOn();
}

void TLFSM_SwitchToPhase4(void)
{
    gTlfsmData.activePhase = TLFSM_PHASE_4_8;
    gTlfsmData.previousPhase = TLFSM_PHASE_3;

    LDRV_EwweRedLampOn();    
}

void TLFSM_SwitchToPhase_1_or_5(void)
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
            
}

void TLFSM_SwitchToPhase6(void)
{
    gTlfsmData.activePhase = TLFSM_PHASE_6;
    gTlfsmData.previousPhase = TLFSM_PHASE_5;

    LDRV_NssnDontWalkLampFlashing();    
}

void TLFSM_SwitchToPhase7(void)
{
    gTlfsmData.activePhase = TLFSM_PHASE_7;
    gTlfsmData.previousPhase = TLFSM_PHASE_6;

    LDRV_NssnDontWalkLampOn();
    LDRV_NssnYellowLampOn();    
}

void TLFSM_SwitchToPhase8(void)
{
    gTlfsmData.activePhase = TLFSM_PHASE_4_8;
    gTlfsmData.previousPhase = TLFSM_PHASE_7;

    LDRV_NssnRedLampOn();    
}
