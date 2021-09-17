#ifndef _ELEVATOR_LOGIC_
#define _ELEVATOR_LOGIC_

#ifdef TEST
#include "type.h"
extern ELFSM_DATA_S gElv_data;

#endif

/**
 *\brief Perform elevator initialization 
 */
void ELFSM_ElvInit(void);

/**
 *\brief Switch elevator to the next phase
 */
void ELFSM_ElvCabinSwitchToNextPhase(void);

/**
 * \brief Switch door tot the next phase
 */
void ELFSM_DoorSwitchToNextPhase(void);

#endif