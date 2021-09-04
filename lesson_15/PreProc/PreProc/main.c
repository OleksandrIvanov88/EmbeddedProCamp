
#include "framework.h"

int main(void)
{
	TEST_ASSERT_EQUAL_INT(3, 4);

	framework_function1_Expect();

	framework_function1();

	assert_expect();

	return 0;
}