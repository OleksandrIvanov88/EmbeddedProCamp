#ifndef _ELEVATOR_LOGIC_
#define _ELEVATOR_LOGIC_

/**
 *\brief Perform elevator initialization 
 */
void ElvInit(void);

/**
 *\brief Switch elevator to the next phase
 */
void ElvCabinSwitchToNextPhase(void);

/**
 * \brief Switch door tot the next phase
 */
void DoorSwitchToNextPhase(void);

#endif