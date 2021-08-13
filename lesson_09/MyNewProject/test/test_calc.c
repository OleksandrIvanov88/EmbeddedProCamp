#include "unity.h"
#include "calc.h"
#include "mock_rules.h"
void setUp(void)
{
}
void tearDown(void)
{
}
void test_add( void )
{
    int result = 0;
    rules_is_addition_allowed_ExpectAndReturn(1);
    result = calc_add(2,2);
    TEST_ASSERT_EQUAL_INT( 4, result );
}
void test_add_off_nominal( void )
{
    int result = 0;
    rules_is_addition_allowed_ExpectAndReturn(0);
    result = calc_add(2,2);
    TEST_ASSERT_EQUAL_INT( 0, result );
}