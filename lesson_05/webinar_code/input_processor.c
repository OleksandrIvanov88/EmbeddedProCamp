#include "input_processor.h"
#include <stdio.h>

void Input(TABLE_RAW_S* table_raw)
{
      scanf("%s %i %f", table_raw->CpuName, &table_raw->CpuMark, &table_raw->Price);
}