#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *s = (char *)str;
  char cc = (char)c;
  void *res = s21_NULL;
  for (s21_size_t i = 0; i < n; i++) {
    if (s[i] == cc) {
      res = (void *)(s + i);
      i = n;
    }
  }
  return res;
}