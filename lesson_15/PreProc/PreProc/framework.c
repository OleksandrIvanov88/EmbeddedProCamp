#include "framework.h"
#include <stdio.h>
#include <string.h>
void check_int(int expected, int actual, int line_number, char* file_name)
{
	if (expected != actual)
	{
		printf("Fail in line %i: Expected %i, actual %i\r\n", line_number, expected, actual);
		printf("File name: %s\r\n", file_name);
	}
}


void function_call_marker(const char* function_name, int line_number)
{
	printf("Fail in line %i: function %s() is called more than expected\r\n", line_number, function_name);
}

void framework_function1(void)
{
	framework_func1.called = 1;
	if (!framework_func1.expected)
	{
		TEST_FUNCTION_CALL_MARKER(__func__);
	}
}

void framework_function1_CMockExpect(int cmock_line)
{
	framework_func1.expected_line = cmock_line;
	framework_func1.expected = 1;
}

void assert_expect()
{
	if (framework_func1.expected && !framework_func1.called)
	{
		TEST_FUNCTION_EXPECT_MARKER(framework_func1);
	}
}

void function_expect_marker(const char* function_name, int line_number)
{
	printf("Fail: function %s() is expected in line %i but not called\r\n", function_name, line_number);
}