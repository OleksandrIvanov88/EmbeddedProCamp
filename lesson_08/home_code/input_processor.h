#ifndef _INPUT_PROCESSOR_H
#define _INPUT_PROCESSOR_H
#include <stdint.h>

typedef void (*INPUT_PROCESSOR_FP)(char* p_data, uint32_t size_of_data);

void scan_data_init(INPUT_PROCESSOR_FP callback);

void scan_data(void);

#endif
