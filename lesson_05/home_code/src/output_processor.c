
#include "output_processor.h"

#include <stdio.h>

#include "type.h"

void print_data(const Lang_item* item) {
  printf("%*s%u %*s%u %*s%-9s %-5.2f %% %+7.2f %%\n", 5, "", item->pos_2021, 10,
         "", item->pos_2020, 6, "", item->lang, item->raiting, item->trand);
}
