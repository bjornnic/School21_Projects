#include "../s21_sprintf.h"

int s21_sprintf(char *buffer, const char *strFormat, ...) {
  if (buffer == NULL) return 1;
  int index = 0;
  va_list args;
  va_start(args, strFormat);
  while (*strFormat != '\0') {
    if (*strFormat == '%') {
      strFormat++;
      Format format = {false, false, false, false, false, 0, 6, false, 0};
      char specifier = s21_sprintf_parcer(&strFormat, &format, args);
      s21_sprintf_specifier(buffer, specifier, &index, args, &format);
    } else
      append_char(buffer, &index, *strFormat);
    strFormat++;
  }
  buffer[index] = '\0';
  va_end(args);
  return index;
}