#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  const char *n = s21_NULL;
  int found = 0;
  if (*needle == '\0') {
    n = haystack;
  } else {
    for (int i = 0; haystack[i] != '\0' && !found; i++) {
      if (haystack[i] == needle[0]) {
        int j = 0;
        while (needle[j] != '\0' && haystack[i + j] == needle[j]) {
          j++;
        }
        if (needle[j] == '\0') {
          n = &haystack[i];
          found = 1;
        }
      }
    }
  }
  return (char *)n;
}