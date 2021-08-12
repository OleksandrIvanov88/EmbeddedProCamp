#ifndef _INPUT_PROCESSOR_H
#define _INPUT_PROCESSOR_H

#include "type.h"
typedef void (*INPUT_PROCESSOR_FP)(data_type_e data_type, uint32_t pos_2021,
                                   uint32_t pos_2020, myString lang,
                                   float raiting, float trand);

void scan_data_init(INPUT_PROCESSOR_FP callback);

void scan_data(void);

#endif
