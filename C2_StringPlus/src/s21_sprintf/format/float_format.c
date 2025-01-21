#include "../../s21_sprintf.h"

void float_format(char *buffer, double value, int *index, Format *format) {
  // printf("%lf\n", value);
  if ((format->flag_plus && format->flag_space) || format->length == 'h')
    return;
  char temp[1024];
  int float_len = 0;

  floatToString(value, temp, format->precision, &float_len, format);

  if (format->flag_minus && float_len <= format->width) {
    append_string(buffer, index, temp);
    for (int j = 0; j < format->width - float_len; j++) {
      if (format->flag_null)
        append_char(buffer, index, '0');
      else
        append_char(buffer, index, ' ');
    }
  } else {
    for (int j = 0; j < format->width - float_len; j++) {
      if (format->flag_null)
        append_char(buffer, index, '0');
      else
        append_char(buffer, index, ' ');
    }
    append_string(buffer, index, temp);
  }
}