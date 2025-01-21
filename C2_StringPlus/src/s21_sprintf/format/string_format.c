#include "../../s21_sprintf.h"

void string_format(char *buffer, const char *value, int *index,
                   Format *format) {
  if (value == s21_NULL) {
    return;
  }
  char fill_width = ' ';
  if (format->flag_null) fill_width = '0';

  int len_str = s21_strlen(value);
  int precision = len_str;
  if (format->prec && format->precision < len_str)
    precision = format->precision;
  int times = 0;
  if (len_str - format->precision < format->width)
    times = format->width - precision;

  if (format->flag_minus) {
    for (int i = 0; i < precision; i++) {
      append_char(buffer, index, value[i]);
    }
    for (int j = 0; j < times; j++) {
      append_char(buffer, index, fill_width);
    }
  } else {
    for (int j = 0; j < times; j++) {
      append_char(buffer, index, fill_width);
    }
    for (int i = 0; i < precision; i++) {
      append_char(buffer, index, value[i]);
    }
  }
}