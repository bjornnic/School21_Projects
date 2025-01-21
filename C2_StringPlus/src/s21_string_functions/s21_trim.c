#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == s21_NULL || trim_chars == s21_NULL) {
    return s21_NULL;
  }
  const char *start = src;
  while (*start && s21_strchr(trim_chars, *start)) {
    start++;
  }
  const char *end = src + s21_strlen(src) - 1;
  while (end > start && s21_strchr(trim_chars, *end)) {
    end--;
  }
  s21_size_t length = end - start + 1;
  char *result = (char *)malloc(length + 1);
  if (result == s21_NULL) {
    return s21_NULL;
  }
  s21_strncpy(result, start, length);
  result[length] = '\0';

  return result;
}