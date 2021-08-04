
#include "input_processor.h"

#include <stdio.h>

#include "type.h"

void scan_data(table_row_s* item) {
#if TABLE_TYPE == 1
  item->data_type = LANG_DATA_TYPE;
  printf(
      "Enter: Position_2021 | Position_2020 | Language | Rainting | Trends "
      "|\n");
  scanf("%u %u %s %f %f", &item->data.lang.pos_2021, &item->data.lang.pos_2020,
        &item->data.lang.lang[0], &item->data.lang.raiting,
        &item->data.lang.trand);
#endif

#if TABLE_TYPE == 2
  item->data_type = PERSON_DATA_TYPE;
  printf("Enter: Name | Age | Rainting\n");
  scanf("%s %u %f", &item->data.pers.name[0], &item->data.pers.age,
        &item->data.pers.raiting);
#endif
}