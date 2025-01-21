#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *dest_proc = dest;
  const char *src_proc = src;

  while (n > 0 && *src_proc != '\0') {
    *dest_proc++ = *src_proc++;
    --n;
  }
  while (n > 0) {
    *dest_proc++ = '\0';
    --n;
  }
  return dest;
}