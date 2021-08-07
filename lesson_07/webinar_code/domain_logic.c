#include <stdio.h>
#include "domain_logic.h"
#include "type.h"
#include "input_processor.h"
#include "output_processor.h"
#include <string.h> 

static void dl_WriteData(DATA_TYPE_E data_type, myString CpuName, int CpuMark, float Price);

static TABLE_ROW_S table[3];

void Create_table(void)
{
    TABLE_ROW_S * ptrTableRaw = 0;

    IP_Init(dl_WriteData);
    for(ptrTableRaw = &table[0]; ptrTableRaw <= &table[2]; ptrTableRaw++)
    {
        IP_Input();
    }

    OP_Init(table[0].DataType);

    for(ptrTableRaw = &table[0]; ptrTableRaw <= &table[2]; ptrTableRaw++)
    {
        OP_Output(ptrTableRaw);
    }
}

static void dl_WriteData(DATA_TYPE_E data_type, myString CpuName, int CpuMark, float Price)
{
    static int i = 0;
    switch (data_type)
    {
        case CPU_DATA_TYPE:
        {
            table[i].DataType = CPU_DATA_TYPE;
            table[i].Data.cpu.CpuMark = CpuMark;
            table[i].Data.cpu.Price = Price;
            memcpy(&table[i].Data.cpu.CpuName, CpuName, sizeof(myString));
            break;
        }    
        default:
        {
            break;
        }
    }
    i++;
}