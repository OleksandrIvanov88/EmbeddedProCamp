#ifndef _OUTPUT_PROCESSOR_H_
#define _OUTPUT_PROCESSOR_H_

#include "type.h"

void OP_Init(DATA_TYPE_E heading_type);

void OP_Output(TABLE_ROW_S* table_raw);

#endif