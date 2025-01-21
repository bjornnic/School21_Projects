#include "../s21_string.h"

s21_size_t s21_strcspn(const char *str, const char *pattern) {
  s21_size_t min = s21_strlen(str);
  for (s21_size_t x = 0; str[x] != '\0'; x++) {
    for (s21_size_t y = 0; pattern[y] != '\0'; y++) {
      if (str[x] == pattern[y] && x < min) {
        min = x;
      }
    }
  }
  return min;
}
