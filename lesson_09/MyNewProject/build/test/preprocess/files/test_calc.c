#include "mock_rules.h"
#include "src/calc.h"
#include "C:/Ruby27-x64/lib/ruby/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"
void setUp(void)

{

}

void tearDown(void)

{

}

void test_add( void )

{

    int result = 0;

    rules_is_addition_allowed_CMockExpectAndReturn(13, 1);

    result = calc_add(2,2);

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(15), UNITY_DISPLAY_STYLE_INT);

}

void test_add_off_nominal( void )

{

    int result = 0;

    rules_is_addition_allowed_CMockExpectAndReturn(20, 0);

    result = calc_add(2,2);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_INT);

}
