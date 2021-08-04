#ifndef _TYPE_H
#define _TYPE_H

#include <stdint.h>
typedef char myString[31];

typedef enum { LANG_DATA_TYPE = 1, PERSON_DATA_TYPE } data_type_e;

typedef struct {
  uint32_t pos_2021;
  uint32_t pos_2020;
  myString lang;
  float raiting;
  float trand;
} lang_item_s;

typedef struct {
  myString name;
  uint32_t age;
  float raiting;
} person_s;

typedef union {
  lang_item_s lang;
  person_s pers;

} table_row_data_u;

typedef struct {
  data_type_e data_type;
  table_row_data_u data;
} table_row_s;

#endif