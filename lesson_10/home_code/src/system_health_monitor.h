/*
 * system_health_monitor.h
 *
 *  Created on: Aug 16, 2021
 *      Author: Alexandr.Ivanov
 */

#ifndef SRC_SYSTEM_HEALTH_MONITOR_H_
#define SRC_SYSTEM_HEALTH_MONITOR_H_

typedef enum
{
    INVALID = 0,
    VALID = 1,

}BOOLEAN_E;


/**
 * \brief This function checks whether passed parameters valid or not
 *  \param speed - vehicle speed (km/h). Range [0..180]
 *  \param gear  - selected gear (number). Range [-1..5].
 * Special values:
 * -1   - Reverse Gear
 *  0   - Neutral
 *  \param rpm   - engine speed (rpm). Range [0..6000]
 *  \param isHandbrakeActive - state of the handbrake.
 * Values:
 *  0   - not Activated
 *  1   - Activated
 *
 *  \return VALID - if all the parameters are in ranges
 *          INVALID - if any parameter is out of range
 */
BOOLEAN_E SHM_AreMovingParametersValid( unsigned short speed,
                                        signed char gear,
                                        unsigned short rpm,
                                        unsigned char isHandbrakeActive );

#endif /* SRC_SYSTEM_HEALTH_MONITOR_H_ */
