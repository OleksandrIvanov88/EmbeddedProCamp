#include <stdio.h>
#include "output_processor.h"
#include "type.h"

void OP_Init(char* buffer)
{
      TABLE_ROW_S* pTableRaw = (TABLE_ROW_DATA_U*)buffer;
      switch(pTableRaw->DataType)
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

void OP_Output(char *buffer)
{
    TABLE_ROW_S* pTableRaw = 0;
    unsigned int i = 0;
    for (i = 0; i <= 2; i++)
    {
        pTableRaw = (TABLE_ROW_S*)buffer + i;
        switch (pTableRaw->DataType)
        {
            case CPU_DATA_TYPE:
            {
                printf("%-31s %8i %11.2f\n", pTableRaw->Data.cpu.CpuName, pTableRaw->Data.cpu.CpuMark,
                    pTableRaw->Data.cpu.Price);
                break;
            }
            case ORDER_DATA_TYPE:
            {
                printf("%-15i %-31s %4i %15.2f %11.2f\n", pTableRaw->Data.order.OrderNumber, pTableRaw->Data.order.CpuName, \
                    pTableRaw->Data.order.Number, pTableRaw->Data.order.Price, \
                    pTableRaw->Data.order.TotalPrice);
                break;
            }
            default:
            {
                printf("Error:incorrect data type\n");
                break;
            }
        }

    }
     
}