
#include <stdio.h>
#include "output_processor.h"
#include "type.h"

void Output_init(char* buffer) {

  table_row_s* ptr_table_row = (table_row_s*)buffer;
  switch (ptr_table_row->data_type) {
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

void print_data(char* buffer) {

    table_row_s* ptr_table_row = NULL;

    for (size_t i = 0; i <= 2; ++i)
    {
        ptr_table_row = (table_row_s*)buffer + i;
        switch (ptr_table_row->data_type) {
        case LANG_DATA_TYPE: {
            printf("%*s%u %*s%u %*s%-9s %-5.2f %% %+7.2f %%\n", 5, "",
                ptr_table_row->data.lang.pos_2021, 10, "", ptr_table_row->data.lang.pos_2020, 6, "",
                ptr_table_row->data.lang.lang, ptr_table_row->data.lang.raiting,
                ptr_table_row->data.lang.trand);
            break;
        }
        case PERSON_DATA_TYPE: {
            printf("%-10s %-7u %5.2f\n", &ptr_table_row->data.pers.name[0],
                ptr_table_row->data.pers.age, ptr_table_row->data.pers.raiting);
            break;
        }
        default: {
            fprintf(stderr, "Incorect data type for output\n");
            break;
        }
    }
  }
}
