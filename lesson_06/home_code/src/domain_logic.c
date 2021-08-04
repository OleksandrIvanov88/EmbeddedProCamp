
#include "domain_logic.h"

#include <stdint.h>
#include <stdio.h>

#include "input_processor.h"
#include "output_processor.h"
#include "type.h"

#define NLINE (sizeof(data) / sizeof(Lang_item))

void create_table(void) {
  printf("Enter the amount of tabel lines = ");
  int32_t lines_number = 0;
  scanf("%i", &lines_number);
  table_row_s data[lines_number];

  table_row_s* ptrData = NULL;

  for (ptrData = &data[0]; ptrData <= &data[lines_number - 1]; ++ptrData) {
    scan_data(ptrData);
  }

  Output_init(data[0].data_type);

  for (ptrData = &data[0]; ptrData <= &data[lines_number - 1]; ++ptrData) {
    print_data(ptrData);
  }
}