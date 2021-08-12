
#include <stdio.h>
#include <string.h>
#include "input_processor.h"
#include "type.h"

#pragma warning(disable: 4996)


static INPUT_PROCESSOR_FP InputCallBack;

void IP_Init(INPUT_PROCESSOR_FP callback)
{
    InputCallBack = callback;
#if TABLE_TYPE == 1
    printf("-----------------------------------------------------------\n");
    printf("| %-31s | %4s | %s |\n", "CPU", "CPU Mark", "Price (USD)");
    printf("-----------------------------------------------------------\n");
#endif

#if TABLE_TYPE == 2
    printf("------------------------------------------------------------------------------------------\n");
    printf("| %s | %-31s | %4s | %s | %s\n", "Order number", "CPU name", "Number", \
        "Price (USD)", "Total Price(USD)");
    printf("------------------------------------------------------------------------------------------\n");
#endif

}

void IP_Input(void)
{
    TABLE_ROW_S tableRaw;
    unsigned int i = 0;
    for (i = 0; i <= 2; i++)
    {
        memset(&tableRaw, 0, sizeof(TABLE_ROW_S));
#if TABLE_TYPE == 1    

        tableRaw.DataType = CPU_DATA_TYPE;
        scanf("%s %i %f", &tableRaw.Data.cpu.CpuName, &tableRaw.Data.cpu.CpuMark, &tableRaw.Data.cpu.Price);
#endif 

#if TABLE_TYPE == 2
        tableRaw.DataType = ORDER_DATA_TYPE;
        scanf("%u %s %u %f", &tableRaw.Data.order.OrderNumber,&tableRaw.Data.order.CpuName, \
            & tableRaw.Data.order.Number, &tableRaw.Data.order.Price);
        tableRaw.Data.order.TotalPrice = tableRaw.Data.order.Price * tableRaw.Data.order.Number;
#endif
        InputCallBack((char*)&tableRaw, sizeof(TABLE_ROW_S));
    }
}