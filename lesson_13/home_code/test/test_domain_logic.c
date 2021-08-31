#include "unity.h"
#include "domain_logic.h"
#include "mock_input_processor.h"
#include "mock_output_processor.h"
#include <string.h> 




static INPUT_PROCESSOR_FP ut_callback;
static void ut_IP_Init_callback(INPUT_PROCESSOR_FP callback, int cmock_num_calls)
{
    ut_callback = callback;
}

char input_buffer[] = {1, 2, 3, 4, 5, 6};
static void ut_IP_Input_callback(int cmock_num_calls)
{
    ut_callback(input_buffer, sizeof(input_buffer));
}

char output_buffer[sizeof(input_buffer)];
static void ut_OP_Init_callback(char* buffer, int cmock_num_calls)
{
     memcpy(output_buffer, buffer, sizeof(output_buffer));
}

static void ut_OP_Output_callback(char* buffer, int cmock_num_calls)
{}



void setUp(void)
{

}

void tearDown(void)
{
}

/**
 * Given table is not created 
 * When Create_table() called 
 * Then input init shall be compleated 
 * And output init shall be complated  
 * And data form input_buffer should be copied to output_buffer
 */
void test_create_table(void)
{
    //assert
    IP_Init_Stub(ut_IP_Init_callback);
    IP_Input_Stub(ut_IP_Input_callback);
    OP_Init_Stub(ut_OP_Init_callback);
    OP_Output_Stub(ut_OP_Output_callback);
    
    //act
    Create_table();

    //testing if data was copied correctly by dl_WriteData() callback function from input_buffer to output_buffer  
    for (size_t i = 0; i < sizeof(input_buffer); ++i)
    {
        TEST_ASSERT_EQUAL_INT(input_buffer[i] , output_buffer[i]);
    }
}