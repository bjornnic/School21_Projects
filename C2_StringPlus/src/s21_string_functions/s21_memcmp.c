#include "../s21_string.h"
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *s1 = (char *)str1;
  char *s2 = (char *)str2;
  int res = 0;
  for (s21_size_t i = 0; i < n && res == 0; i++) {
    if (s1[i] != s2[i]) {
      res = s1[i] - s2[i];
    }
  }
  return res;
}