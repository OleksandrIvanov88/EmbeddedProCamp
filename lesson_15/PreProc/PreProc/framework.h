#pragma once
#include<stdint.h>

void check_int(int expected, int actual, int line_number, char* file_name);
#define TEST_ASSERT_EQUAL_INT(expected, actual) check_int(expected, actual, __LINE__, __FILE__)

void framework_function1(void);

typedef struct {

	uint8_t called;
	uint8_t expected;
	uint32_t expected_line;
}s_function_meta;

static s_function_meta framework_func1;

#define TEST_FUNCTION_CALL_MARKER(f_name)				   \
		do{												   \
			const char* function_name = f_name;            \
			function_call_marker(function_name, __LINE__); \
		} while (0)
void function_call_marker(const char* function_name, int line_number);

#define framework_function1_Expect() framework_function1_CMockExpect(__LINE__) 
void framework_function1_CMockExpect(int cmock_line);

void assert_expect();

#define TEST_FUNCTION_EXPECT_MARKER(f_name)				  \
		do{												  \
			const char* function_name = #f_name;          \
			function_expect_marker(function_name,         \
                          framework_func1.expected_line); \
		} while (0)
void function_expect_marker(const char* function_name, int line_number);