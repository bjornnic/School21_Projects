#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *pntr = s21_NULL;
  while (*str != '\0') {
    if (*str == (char)c) pntr = (char *)str;
    str++;
  }
  if (c == '\0') {
    pntr = (char *)str;
  }
  return pntr;
}
