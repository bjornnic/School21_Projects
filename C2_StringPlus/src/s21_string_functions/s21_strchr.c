#include "../s21_string.h"

const char *s21_strchr(const char *str, int c) {
  int str_len = s21_strlen(str) + 1;
  const char *result = s21_NULL;

  for (int x = 0; x < str_len && result == s21_NULL; x += 1)
    if (str[x] == c) result = (str + x);

  return result;
}