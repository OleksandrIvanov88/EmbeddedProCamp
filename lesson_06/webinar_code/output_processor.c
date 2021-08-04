#include "output_processor.h"
#include <stdio.h>

void OP_Init(DATA_TYPE_E heading_type)
{
      if (heading_type == CPU_DATA_TYPE)
      {
            printf("-----------------------------------------------------------\n");
            printf("| %-31s | %4s | %s |\n", "CPU", "CPU Mark", "Price (USD)");
            printf("-----------------------------------------------------------\n");
      } else if(heading_type == ORDER_DATA_TYPE) 
      {
            printf("------------------------------------------------------------------------------------------\n");
            printf("| %s | %-31s | %4s | %s | %s\n", "Order number", "CPU name", "Number",\
                                                    "Price (USD)", "Total Price(USD)");
            printf("------------------------------------------------------------------------------------------\n");
      } else 
      {
            printf("Error: encorect heading_type\n");
      }
}

void OP_Output(TABLE_ROW_S *table_raw)
{
      if(table_raw->DataType == CPU_DATA_TYPE)
      {
            printf("%-31s %8i %11.2f\n", table_raw->Data.cpu.CpuName, table_raw->Data.cpu.CpuMark, table_raw->Data.cpu.Price);
      } else if (table_raw->DataType == ORDER_DATA_TYPE)
      {

            printf("%-15i %-31s %4i %15.2f %11.2f\n",   table_raw->Data.order.OrderNumber, table_raw->Data.order.CpuName,\
                                                      table_raw->Data.order.Number, table_raw->Data.order.Price,  \
                                                      table_raw->Data.order.TotalPrice);

      } else 
      {
            printf("Error:incorrect data type\n");
      }
      
}