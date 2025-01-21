#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  // if (dest == s21_NULL || src = s21_NULL) {
  //     return s21_NULL;
  // }

  char *d = (char *)dest;
  const char *s = (const char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }

  return dest;
}