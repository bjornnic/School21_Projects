#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *end_str = dest;
  while (*end_str != '\0') {
    end_str++;
  }

  for (s21_size_t i = 0; i < n && *src != '\0'; ++i) {
    *end_str++ = *src++;
  }

  *end_str = '\0';

  return dest;
}
