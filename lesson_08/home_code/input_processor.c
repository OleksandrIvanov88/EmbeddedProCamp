
#include <stdio.h>
#include <stdlib.h>
#include "input_processor.h"
#include "type.h"

#pragma warning(disable: 4996)



static INPUT_PROCESSOR_FP initial_callback = NULL;

void scan_data_init(INPUT_PROCESSOR_FP callback) {
  if (NULL == callback) {
    fprintf(stderr, "callback is NULL\n");
    exit(1);
  }
  initial_callback = callback;
}

void scan_data(void) {
    for (size_t i = 0; i <= 2; ++i)
    {
        table_row_s table_row;
        memset(&table_row, 0, sizeof(table_row_s));
#if TABLE_TYPE == 1

        table_row.data_type = LANG_DATA_TYPE;
        printf(
            "Enter: Position_2021 | Position_2020 | Language | Rainting | Trends "
            "|\n");
        scanf("%u %u %s %f %f", &table_row.data.lang.pos_2021, &table_row.data.lang.pos_2020, &table_row.data.lang.lang[0], 
                                                                  &table_row.data.lang.raiting, &table_row.data.lang.trand);
     
#endif

#if TABLE_TYPE == 2
        table_row.data_type = PERSON_DATA_TYPE;
        printf("Enter: Name | Age | Rainting\n");
        scanf("%s %u %f", &table_row.data.pers.name[0], &table_row.data.pers.age,
            &table_row.data.pers.raiting);
#endif
        if (NULL == initial_callback) {
            fprintf(stderr, "initial_callback is NULL\n");
            exit(1);
         }
        initial_callback((char*)&table_row, sizeof(table_row_s));

    }
}