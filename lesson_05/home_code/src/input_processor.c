
#include "../inc/input_processor.h"

#include <stdio.h>

#include "../inc/type.h"

void scan_data(Lang_item* item) {
  printf(
      "Enter: Position_2021 | Position_2020 | Language | Rainting | Trends "
      "|\n");
  scanf("%u %u %s %f %f", &item->pos_2021, &item->pos_2020, &item->lang[0],
        &item->raiting, &item->trand);
}