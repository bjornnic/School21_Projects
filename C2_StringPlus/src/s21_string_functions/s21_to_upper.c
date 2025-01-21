#include "../s21_string.h"

char *s21_to_upper(const char *str) {
  if (str == s21_NULL) {
    return s21_NULL;
  }
  s21_size_t len = s21_strlen(str);
  char *str_upper = (char *)malloc(len + 1);
  if (str_upper == s21_NULL) {
    return s21_NULL;
  }
  for (s21_size_t i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str_upper[i] = str[i] - 32;
    } else {
      str_upper[i] = str[i];
    }
  }
  str_upper[len] = '\0';
  return str_upper;
}
