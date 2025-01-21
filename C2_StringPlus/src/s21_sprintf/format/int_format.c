#include "../../s21_sprintf.h"

void int_format(char *buffer, int value, int *index, Format *format) {
  char temp[1024];
  int len_str = 0;
  if (value < 0 && format->flag_null) {
    append_char(buffer, index, '-');
    format->width -= 1;
    value *= -1;
  }
  intToString(value, temp, &len_str);
  int times = len_str;
  if (format->precision > len_str && format->prec) times = format->precision;

  if (format->flag_plus && value > 0)
    append_char(buffer, index, '+');
  else if (format->flag_space && value > 0)
    append_char(buffer, index, ' ');

  char fill_width = ' ';  // символ, которым заполняем ширину
  if (format->flag_null) fill_width = '0';

  // если есть флаг '-', то печатаем значение, потом проходимся циклом
  // по разнице ширины и длины и переносим fill_with
  if (format->flag_minus) {
    if (format->prec) {
      for (int i = 0; i < format->precision - len_str; i++)
        append_char(buffer, index, '0');
    }
    append_string(buffer, index, temp);
  }
  for (int j = 0; j < format->width - times; j++) {
    if (format->flag_null)
      append_char(buffer, index, fill_width);
    else
      append_char(buffer, index, fill_width);
  }

  if (!format->flag_minus) {
    if (format->prec) {
      for (int i = 0; i < format->precision - len_str; i++)
        append_char(buffer, index, '0');
    }
    append_string(buffer, index, temp);
  }
}