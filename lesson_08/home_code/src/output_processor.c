
#include "output_processor.h"

#include <stdio.h>

#include "type.h"

void Output_init(data_type_e data_type) {
  switch (data_type) {
    case LANG_DATA_TYPE: {
      printf("------------------------------------------------------\n");
      printf("| %5s | %5s | %-10s| %5s | %5s |\n", "May 2021", "May 2020",
             "Language", "Raiting", "Trends");
      printf("------------------------------------------------------\n");
      break;
    }
    case PERSON_DATA_TYPE: {
      printf("---------------------------\n");
      printf("| %5s | %5s | %5s |\n", "Name", "Age", "Raiting");
      printf("---------------------------\n");
      break;
    }
    default: {
      fprintf(stderr, "Incorect data type for output\n");
      break;
    }
  }
}

void print_data(const table_row_s* item) {
  switch (item->data_type) {
    case LANG_DATA_TYPE: {
      printf("%*s%u %*s%u %*s%-9s %-5.2f %% %+7.2f %%\n", 5, "",
             item->data.lang.pos_2021, 10, "", item->data.lang.pos_2020, 6, "",
             item->data.lang.lang, item->data.lang.raiting,
             item->data.lang.trand);
      break;
    }
    case PERSON_DATA_TYPE: {
      printf("%-10s %-7u %5.2f\n", &item->data.pers.name[0],
             item->data.pers.age, item->data.pers.raiting);
      break;
    }
    default: {
      fprintf(stderr, "Incorect data type for output\n");
      break;
    }
  }
}
