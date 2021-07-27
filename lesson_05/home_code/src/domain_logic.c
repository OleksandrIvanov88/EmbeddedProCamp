
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
  Lang_item data[lines_number];

  Lang_item* ptrData = NULL;

  for (ptrData = &data[0]; ptrData <= &data[lines_number - 1]; ++ptrData) {
    scan_data(ptrData);
  }

  printf("------------------------------------------------------\n");
  printf("| %5s | %5s | %-10s| %5s | %5s |\n", "May 2021", "May 2020",
         "Language", "Raiting", "Trends");
  printf("------------------------------------------------------\n");

  for (ptrData = &data[0]; ptrData <= &data[lines_number - 1]; ++ptrData) {
    print_data(ptrData);
  }
}