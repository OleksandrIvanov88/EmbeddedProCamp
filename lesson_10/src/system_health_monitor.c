/*
 * system_health_monitor.c
 *
 *  Created on: 19 серп. 2021 р.
 *      Author: Alex
 */


#include "system_health_monitor.h"

BOOLEAN_E SHM_AreMovingParametersValid( unsigned short speed,
                                        signed char gear,
                                        unsigned short rpm,
                                        unsigned char isHandbrakeActive )
{
	 BOOLEAN_E result = VALID;

	if (speed > 180 )
	{
		result = INVALID;
	}
	if ((gear < -1) || (gear > 5))
	{
		result = INVALID;
	}
	if (rpm > 6000)
	{
		result = INVALID;
	}
	if (isHandbrakeActive > 1)
	{
		result = INVALID;
	}
	return result;
}
