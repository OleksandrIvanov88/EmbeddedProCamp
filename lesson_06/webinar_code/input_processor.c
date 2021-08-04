#include "input_processor.h"
#include <stdio.h>

void IP_Init(void)
{
#if TABLE_TYPE == 1      
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


void IP_Input(TABLE_ROW_S *table_raw)
{
#if TABLE_TYPE == 1    
      table_raw->DataType = CPU_DATA_TYPE;
      scanf("%s %i %f", table_raw->Data.cpu.CpuName, &table_raw->Data.cpu.CpuMark, &table_raw->Data.cpu.Price);
#endif 

#if TABLE_TYPE == 2
      table_raw->DataType = ORDER_DATA_TYPE;
      scanf("%u %s %u %f", &table_raw->Data.order.OrderNumber, table_raw->Data.order.CpuName,\
                                                      &table_raw->Data.order.Number, &table_raw->Data.order.Price);
      table_raw->Data.order.TotalPrice = table_raw->Data.order.Price * table_raw->Data.order.Number;                                                
#endif

}