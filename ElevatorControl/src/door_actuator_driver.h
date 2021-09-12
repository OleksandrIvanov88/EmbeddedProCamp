#ifndef _DOOR_ACTUATOR_DRIVER_
#define _DOOR_ACTUATOR_DRIVER_

/**
 * \brief Performs Door Actuators Initialization 
 */
void DoorActuatorInit(void);

/**
 *\brief Switch off door actuators   
 */
void DoorActuatorsOff(void);

/**
 *\brief Switch on opening mode for door actuators  
 */
void DoorActuatorsOpening(void);

/**
 *\brief Switch on сlosening mode for door actuators  
 */
void DoorActuatorsClosening(void);

#endif