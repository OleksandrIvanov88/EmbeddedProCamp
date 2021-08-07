#include "input_processor.h"
#include <stdio.h>

#define TABLE_TYPE 1

static INPUT_PROCESSOR_FP InputCallBack;

void IP_Init(INPUT_PROCESSOR_FP callback)
{
#if TABLE_TYPE == 1
      InputCallBack = callback;      
      printf("-----------------------------------------------------------\n");
      printf("| %-31s | %4s | %s |\n", "CPU", "CPU Mark", "Price (USD)");
      printf("-----------------------------------------------------------\n");
#endif

#if TABLE_TYPE == 2
      printf("------------------------------------------------------------------------------------------\n");
      printf("| %s | %-31s | %4s | %s | %s\n", "Order number", "CPU name", "Number",\
                                                    "Price (USD)", "Total Price(USD)");
      printf("------------------------------------------------------------------------------------------\n");
#endif
}


void IP_Input(void)
{
#if TABLE_TYPE == 1    
      myString CpuName;
      int CpuMark;
      float Price;
      scanf("%s %i %f", CpuName, &CpuMark, &Price);
      InputCallBack(CPU_DATA_TYPE, CpuName, CpuMark, Price);
#endif 

#if TABLE_TYPE == 2
      table_raw->DataType = ORDER_DATA_TYPE;
      scanf("%u %s %u %f", &table_raw->Data.order.OrderNumber, table_raw->Data.order.CpuName,\
                                                      &table_raw->Data.order.Number, &table_raw->Data.order.Price);
      table_raw->Data.order.TotalPrice = table_raw->Data.order.Price * table_raw->Data.order.Number;                                                
#endif

}