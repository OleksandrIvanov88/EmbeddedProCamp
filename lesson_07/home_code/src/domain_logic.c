
#include "domain_logic.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "input_processor.h"
#include "output_processor.h"
#include "type.h"

#define LINES_NUMBER (3)
static table_row_s data[LINES_NUMBER];

void save_data(data_type_e data_type, uint32_t pos_2021, uint32_t pos_2020,
               myString lang, float raiting, float trand);

void create_table(void) {
  table_row_s* ptrData = NULL;

  scan_data_init(save_data);

  for (ptrData = &data[0]; ptrData <= &data[LINES_NUMBER - 1]; ++ptrData) {
    scan_data();
  }

  Output_init(data[0].data_type);

  for (ptrData = &data[0]; ptrData <= &data[LINES_NUMBER - 1]; ++ptrData) {
    print_data(ptrData);
  }
}

void save_data(data_type_e data_type, uint32_t pos_2021, uint32_t pos_2020,
               myString lang, float raiting, float trand) {
  static int i = 0;
  switch (data_type) {
    case LANG_DATA_TYPE: {
      data[i].data_type = LANG_DATA_TYPE;
      data[i].data.lang.pos_2021 = pos_2021;
      data[i].data.lang.pos_2020 = pos_2020;
      data[i].data.lang.raiting = raiting;
      data[i].data.lang.trand = trand;
      memcpy(&data[i].data.lang.lang, lang, sizeof(myString));
      break;
    }
    default: {
      fprintf(stderr, "Incorect data type for save_data\n");
      break;
    }
  }
  ++i;
}