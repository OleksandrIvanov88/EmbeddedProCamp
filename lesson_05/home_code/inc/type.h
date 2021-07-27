#ifndef _TYPE_H
#define _TYPE_H

#include <stdint.h>
typedef char myString[31];

typedef struct {
  uint32_t pos_2021;
  uint32_t pos_2020;
  myString lang;
  float raiting;
  float trand;
} Lang_item;

#endif