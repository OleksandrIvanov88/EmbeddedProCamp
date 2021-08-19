/*
 * system_health_monitor.c
 *
 *  Created on: 19 серп. 2021 р.
 *      Author: Alex
 */

#include "unity.h"
#include "system_health_monitor.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/**
 * Given all parameters equal to a minimal valid values
 * When SHM_AreMovingParametersValid(void) is called
 * Then it  shall return VALID
 */

void test_MovingParameters_MinimalValues(void)
{
	BOOLEAN_E actual = INVALID;
	actual = SHM_AreMovingParametersValid(0, -1, 0, 0);
	TEST_ASSERT_EQUAL_INT(VALID, actual);
}


/**
 * Given all parameters equal to a maximum valid values
 * When SHM_AreMovingParametersValid(void) is called
 * Then it  shall return VALID
 */

void test_MovingParameters_MaximumlValues(void)
{
	BOOLEAN_E actual = INVALID;
	actual = SHM_AreMovingParametersValid(180, 5, 6000, 1);
	TEST_ASSERT_EQUAL_INT(VALID, actual);
}


/**
 * Given all parameters equal to a minimal valid values
 * But vehicle speed is equal to 181
 * When SHM_AreMovingParametersValid(void) is called
 * Then it  shall return INVALID
 */

void test_MovingParameters_VehicleSpeed_OutOfMax(void)
{
	BOOLEAN_E actual = INVALID;
	actual = SHM_AreMovingParametersValid(181, -1, 0, 0);
	TEST_ASSERT_EQUAL_INT(INVALID, actual);
}


/**
 * Given all parameters equal to a minimal valid values
 * But selected gear is equal to 6
 * When SHM_AreMovingParametersValid(void) is called
 * Then it  shall return INVALID
 */

void test_MovingParameters_Gear_OutOfMax(void)
{
	BOOLEAN_E actual = INVALID;
	actual = SHM_AreMovingParametersValid(0, 6, 0, 0);
	TEST_ASSERT_EQUAL_INT(INVALID, actual);
}


/**
 * Given all parameters equal to a minimal valid values
 * But selected gear is equal to -2
 * When SHM_AreMovingParametersValid(void) is called
 * Then it  shall return INVALID
 */

void test_AreMovingParameters_Gear_OutOfMin(void)
{
	BOOLEAN_E actual = INVALID;
	actual = SHM_AreMovingParametersValid(0, -2, 0, 0);
	TEST_ASSERT_EQUAL_INT(INVALID, actual);
}


/**
 * Given all parameters equal to a minimal valid values
 * But engine speed is equal to 6001
 * When SHM_AreMovingParametersValid(void) is called
 * Then it  shall return INVALID
 */
void test_MovingParameters_Rpm_OutOfMax(void)
{
	BOOLEAN_E actual = INVALID;
	actual = SHM_AreMovingParametersValid(0, -1, 6001, 0);
	TEST_ASSERT_EQUAL_INT(INVALID, actual);
}


/**
 * Given all parameters equal to a minimal valid values
 * But handbrake is equal to 2
 * When SHM_AreMovingParametersValid(void) is called
 * Then it  shall return INVALID
 */
void test_MovingParameters_Handbrake(void)
{
	BOOLEAN_E actual = INVALID;
	actual = SHM_AreMovingParametersValid(0, -1, 0, 2);
	TEST_ASSERT_EQUAL_INT(INVALID, actual);
}

