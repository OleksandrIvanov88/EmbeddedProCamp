#include "output_processor.h"
#include <stdio.h>

void OP_Init(DATA_TYPE_E heading_type)
{
      switch(heading_type)
      {
            case CPU_DATA_TYPE:
            {
                  printf("-----------------------------------------------------------\n");
                  printf("| %-31s | %4s | %s |\n", "CPU", "CPU Mark", "Price (USD)");
                  printf("-----------------------------------------------------------\n");
                  break;
            }      
            case ORDER_DATA_TYPE:
            {
                  printf("------------------------------------------------------------------------------------------\n");
                  printf("| %s | %-31s | %4s | %s | %s\n", "Order number", "CPU name", "Number",\
                                                      "Price (USD)", "Total Price(USD)");
                  printf("------------------------------------------------------------------------------------------\n");
                  break;
            } 
            default:
            {
                  printf("Error: encorect heading_type\n");
                  break;
            }
      }
}

void OP_Output(TABLE_ROW_S *table_raw)
{
      switch(table_raw->DataType)
      {     case CPU_DATA_TYPE:
            {
                  printf("%-31s %8i %11.2f\n", table_raw->Data.cpu.CpuName, table_raw->Data.cpu.CpuMark, 
                                                                              table_raw->Data.cpu.Price);
                  break;
            }      
            case ORDER_DATA_TYPE:
            {
                  printf("%-15i %-31s %4i %15.2f %11.2f\n",   table_raw->Data.order.OrderNumber, table_raw->Data.order.CpuName,\
                                                      table_raw->Data.order.Number, table_raw->Data.order.Price,  \
                                                      table_raw->Data.order.TotalPrice);
                  break;
            }
            default: 
            {
                  printf("Error:incorrect data type\n");
                  break;           
            }
      }
}