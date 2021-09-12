#ifndef _MOTOR_DRIVER_H
#define _MOTOR_DRIVER_H


/**
 * \brief Performs Motor Driver Initialization 
 */
void MotorInit(void);

/**
 * \brief Increase motor speed in the up direction. 
 */
void MotorFastSpeedUp(void);

/**
 * \brief Switch on motor speed in the up direction. 
 */
void MotorLowSpeedUp(void);

/**
 * \brief Switch off motor. 
 */
void MotorSpeedOff(void);

/**
 * \brief Switch on motor in the down direction. 
 */
void MotorLowSpeedDown(void);

/**
 * \brief Increase motor speed in the down direction. 
 */
void MotorFastSpeedDown(void);







#endif