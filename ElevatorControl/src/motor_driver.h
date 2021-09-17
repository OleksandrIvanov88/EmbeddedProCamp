#ifndef _MOTOR_DRIVER_H
#define _MOTOR_DRIVER_H


/**
 * \brief Performs Motor Driver Initialization 
 */
void MDRV_Init(void);

/**
 * \brief Increase motor speed in the up direction. 
 */
void MDRV_FastSpeedUp(void);

/**
 * \brief Switch on motor speed in the up direction. 
 */
void MDRV_LowSpeedUp(void);

/**
 * \brief Switch off motor. 
 */
void MDRV_SpeedOff(void);

/**
 * \brief Switch on motor in the down direction. 
 */
void MDRV_LowSpeedDown(void);

/**
 * \brief Increase motor speed in the down direction. 
 */
void MDRV_FastSpeedDown(void);







#endif