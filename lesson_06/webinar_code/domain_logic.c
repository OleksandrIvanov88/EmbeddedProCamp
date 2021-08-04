#include <stdio.h>
#include "domain_logic.h"
#include "type.h"
#include "input_processor.h"
#include "output_processor.h"

void Create_table(void)
{
    TABLE_ROW_S table[3];

    TABLE_ROW_S * ptrTableRaw = 0;

    IP_Init();
    for(ptrTableRaw = &table[0]; ptrTableRaw <= &table[2]; ptrTableRaw++)
    {
        IP_Input(ptrTableRaw);
    }
    OP_Init(table[0].DataType);
    for(ptrTableRaw = &table[0]; ptrTableRaw <= &table[2]; ptrTableRaw++)
    {
        OP_Output(ptrTableRaw);
    }
}