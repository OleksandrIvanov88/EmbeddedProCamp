#ifndef _CABIN_BRAKE_DRIVER_H_
#define _CABIN_BRAKE_DRIVER_H_

/**
 * \brief Performs Cabin Brakes Initialization 
 */
void CBDRV_Init(void);

/**
 * \brief Switch on cabin's brakes. 
 */
void CBDRV_BrakesOn(void);

/**
 * \brief Switch off cabin's brakes. 
 */
void CBDRV_BrakesOff(void);

#endif