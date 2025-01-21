#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  s21_size_t length = s21_strlen(str1);
  s21_size_t length2 = s21_strlen(str2);
  for (int i = 0; i < (int)length; i++) {
    for (int j = 0; j < (int)length2; j++) {
      if (str1[i] == str2[j]) {
        return (char *)&str1[i];
      }
    }
  }
  return s21_NULL;
}