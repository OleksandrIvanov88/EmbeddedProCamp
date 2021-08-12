
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "domain_logic.h"
#include "input_processor.h"
#include "output_processor.h"

static char buffer[1024];

void save_data(char* p_data, uint32_t size_of_data);

void create_table(void) {

  scan_data_init(save_data);
  scan_data();
  Output_init(buffer);
  print_data(buffer);
}

void save_data(char* p_data, uint32_t size_of_data){
  static int i = 0;
  memcpy(&buffer[size_of_data * i], p_data, size_of_data);
  ++i;
}