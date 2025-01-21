#include "../s21_string.h"

char *s21_to_lower(const char *str) {
  if (str == s21_NULL) {
    return s21_NULL;
  }
  s21_size_t len = s21_strlen(str);
  char *str_lower = (char *)malloc(len + 1);
  if (str_lower == s21_NULL) {
    return s21_NULL;
  }
  for (s21_size_t i = 0; i < len; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str_lower[i] = str[i] + 32;
    } else {
      str_lower[i] = str[i];
    }
  }
  str_lower[len] = '\0';
  return str_lower;
}