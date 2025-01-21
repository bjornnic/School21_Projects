#include "../../s21_sprintf.h"

void char_format(char *buffer, char value, int *index, Format *format) {
  if (format->flag_minus && format->width > 1) {
    append_char(buffer, index, value);
    for (int j = 0; j < format->width - 1; j++) {
      if (format->flag_null)
        append_char(buffer, index, '0');
      else
        append_char(buffer, index, ' ');
    }
  } else {
    for (int j = 0; j < format->width - 1; j++) {
      if (format->flag_null)
        append_char(buffer, index, '0');
      else
        append_char(buffer, index, ' ');
    }
    append_char(buffer, index, value);
  }
}