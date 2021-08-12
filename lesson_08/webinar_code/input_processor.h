#ifndef _INPUT_PROCESSOR_H_
#define _INPUT_PROCESSOR_H_


typedef void (*INPUT_PROCESSOR_FP)(char* pData, unsigned int sizeOfData);

void IP_Init(INPUT_PROCESSOR_FP callback);

void IP_Input(void);

#endif