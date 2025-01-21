#include "../s21_string.h"

char *s21_strtok(char *str, const char *sep) {
  static char *next = s21_NULL;
  char *token = s21_NULL;
  if (str != s21_NULL) next = str;

  while (next != s21_NULL && *next && s21_strchr(sep, *next)) next++;

  if (next == s21_NULL || *next == '\0')
    token = s21_NULL;
  else {
    token = next;
    while (*next && !s21_strchr(sep, *next)) next++;
    if (*next) {
      *next = '\0';
      next++;
    } else {
      next = s21_NULL;
    }
  }

  return token;
}
