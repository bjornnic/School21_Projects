#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == s21_NULL || str == s21_NULL) {
    return s21_NULL;
  }
  s21_size_t src_length = s21_strlen(src);
  s21_size_t str_length = s21_strlen(str);
  if (start_index > src_length) {
    return s21_NULL;
  }
  s21_size_t general_length = src_length + str_length + 1;
  char *result = (char *)malloc(general_length);
  if (result == s21_NULL) {
    return s21_NULL;
  }
  s21_memcpy(result, src, start_index);
  s21_memcpy(result + start_index, str, str_length);
  s21_memcpy(result + start_index + str_length, src + start_index,
             src_length - start_index + 1);
  return (void *)result;
}