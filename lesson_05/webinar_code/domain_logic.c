#include <stdio.h>
#include "domain_logic.h"
#include "type.h"
#include "input_processor.h"
#include "output_processor.h"

void Create_table(void)
{
    TABLE_RAW_S table[3];

    TABLE_RAW_S * ptrTableRaw = 0;

    //Heading
    printf("-----------------------------------------------------------\n");
    printf("| %-31s | %4s | %s |\n", "CPU", "CPU Mark", "Price (USD)");
    printf("-----------------------------------------------------------\n");
    for(ptrTableRaw = &table[0]; ptrTableRaw <= &table[2]; ptrTableRaw++)
    {
        Input(ptrTableRaw);
    }
    //Body
    printf("-----------------------------------------------------------\n");
    printf("| %-31s | %4s | %s |\n", "CPU", "CPU Mark", "Price (USD)");
    printf("-----------------------------------------------------------\n");
    for(ptrTableRaw = &table[0]; ptrTableRaw <= &table[2]; ptrTableRaw++)
    {
        Output(ptrTableRaw);
    }
}