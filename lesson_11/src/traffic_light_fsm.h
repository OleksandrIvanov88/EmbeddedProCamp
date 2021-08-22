#ifndef TRAFFIC_LIGHT_FSM_H
#define TRAFFIC_LIGHT_FSM_H

/**
 * \brief Performs FSM initialization
 */
void TLFSM_Init(void);

/**
 * \brief Switches FSM to the next phase according to the traffic standard phases.
 * 
 * Note: This function cannot move FSM to the Default phase.
 */
void TLFSM_SwitchToNextPhase(void);

/**
 * \brief Switches FSM to the Default phase from any active state.
 */
void TLFSM_SwitchToDefaultPhase(void);

#endif /*TRAFFIC_LIGHT_FSM_H*/
