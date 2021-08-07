#ifndef _INPUT_PROCESSOR_H_
#define _INPUT_PROCESSOR_H_

#include "type.h"

typedef void (*INPUT_PROCESSOR_FP)(DATA_TYPE_E data_type, myString CpuName, int CpuMark, float Price);

void IP_Init(INPUT_PROCESSOR_FP callback);

void IP_Input(void);

#endif