#include "../../s21_sprintf.h"

void append_char(char *buffer, int *index, char c) {
  buffer[*index] = c;
  (*index)++;
}

void append_string(char *buffer, int *index, const char *str) {
  while (*str != '\0') {
    append_char(buffer, index, *str);
    str++;
  }
}