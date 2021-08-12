
#include "input_processor.h"

#include <stdio.h>
#include <stdlib.h>

#include "type.h"

#define TABLE_TYPE 1

static INPUT_PROCESSOR_FP initial_callback = NULL;

void scan_data_init(INPUT_PROCESSOR_FP callback) {
  if (NULL == callback) {
    fprintf(stderr, "callback is NULL\n");
    exit(1);
  }
  initial_callback = callback;
}

void scan_data(void) {
#if TABLE_TYPE == 1

  uint32_t pos_2021;
  uint32_t pos_2020;
  myString lang;
  float raiting;
  float trand;
  printf(
      "Enter: Position_2021 | Position_2020 | Language | Rainting | Trends "
      "|\n");
  scanf("%u %u %s %f %f", &pos_2021, &pos_2020, &lang[0], &raiting, &trand);
  if (NULL == initial_callback) {
    fprintf(stderr, "initial_callback is NULL\n");
    exit(1);
  }
  initial_callback(LANG_DATA_TYPE, pos_2021, pos_2020, lang, raiting, trand);
#endif

#if TABLE_TYPE == 2
  item->data_type = PERSON_DATA_TYPE;
  printf("Enter: Name | Age | Rainting\n");
  scanf("%s %u %f", &item->data.pers.name[0], &item->data.pers.age,
        &item->data.pers.raiting);
#endif
}