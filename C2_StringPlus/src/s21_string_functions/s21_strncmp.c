#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  int flag_res = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if ((str1[i] == '\0' || str2[i] == '\0') && flag_res == 0) {
      res = (unsigned char)str1[i] - (unsigned char)str2[i];
      flag_res = 1;
    }
    if (str1[i] != str2[i] && flag_res == 0) {
      res = (unsigned char)str1[i] - (unsigned char)str2[i];
      flag_res = 1;
    }
  }
  return res;
}
