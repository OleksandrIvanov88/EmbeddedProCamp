#ifndef _IPUTS_DRIVER_H_
#define _INPUTS_DRIVER_H_

/**
 * \brief Performs Inputs switches' driver Initialization 
 */
void INDRV_Init(void);


/**
 * \brief Informs about currently  activated cabin's switch
 * @return: 0 - unknown state 
 *          1 - switch MIN is activated 
 *          2 - switch FLOOR HIGH is activated 
 *          3 - switch FLOOR is activated 
 *          4 - switch FLOOR LOW is activated 
 *          5 - switch MAX is activated  
 */
int INDRV_CabinSwitches();

/**
 * \brief Informs about currently  activated door's switch
 * @return: 0 - unknown state 
 *          1 - switch DOOR CLOSED is activated 
 *          2 - switch DOOR OPENED is activated   
 */
int INDRV_DoorSwitches();

/**
 * \brief Informs about currently activated incabin or outcabin switch 
 * @return:-3 - key FLOOR 3 outcabin is activated 
 *         -2 - key FLOOR 2 outcabin  is activated 
 *         -1 - key FLOOR 1 outcabin is activated     
 *          0 - not key activated 
 *          1 - key FLOOR 1 incabin is activated 
 *          2 - key FLOOR 2 incabin  is activated 
 *          3 - key FLOOR 3 incabin is activated 
 *          4 - key STOP in cabin is activated
 */
int INDRV_Keys();


#endif
