/*
 * system_health_monitor.c
 *
 *  Created on: Aug 16, 2021
 *      Author: Alexandr.Ivanov
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
	if ((gear != 0) && (isHandbrakeActive == 1) && (speed > 0))
	{
		result = INVALID;
	}
	return result;
}
