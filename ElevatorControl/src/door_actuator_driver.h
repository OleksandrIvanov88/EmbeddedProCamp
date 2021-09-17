#ifndef _DOOR_ACTUATOR_DRIVER_
#define _DOOR_ACTUATOR_DRIVER_

/**
 * \brief Performs Door Actuators Initialization 
 */
void DADRV_Init(void);

/**
 *\brief Switch off door actuators   
 */
void DADRV_ActuatorsOff(void);

/**
 *\brief Switch on opening mode for door actuators  
 */
void DADRV_ActuatorsOpening(void);

/**
 *\brief Switch on сlosening mode for door actuators  
 */
void DADRV_ActuatorsClosening(void);

#endif