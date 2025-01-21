#include "../../s21_sprintf.h"

void unsigned_int_format(char *buffer, unsigned long int value, int *index,
                         Format *format) {
  // обработка длины типа
  if (format->length == 'h')
    value = (unsigned short int)value;
  else if (format->length == 0)
    value = (unsigned int)value;
  if (format->length == 'l')
    value = (unsigned long)value;
  else if (format->length == 'h')
    value = (unsigned short)value;

  char temp[1024];
  int len_str = 0;
  intToString(value, temp, &len_str);
  int times = len_str;
  if (format->precision > len_str && format->prec) times = format->precision;

  char fill_width = ' ';  // символ, которым заполняем ширину
  if (format->flag_null) fill_width = '0';

  // если есть флаг '-', то печатаем значение, потом проходимся циклом
  // по разнице ширины и длины и переносим fill_with
  if (format->flag_minus) {
    if (format->prec) {
      for (int i = 0; i < format->precision - len_str; i++)
        append_char(buffer, index, '0');
    }
    uToString(value, buffer, index);
  }

  for (int j = 0; j < format->width - times; j++) {
    if (format->flag_null)
      append_char(buffer, index, '0');
    else
      append_char(buffer, index, fill_width);
  }

  if (!format->flag_minus) {
    if (format->prec) {
      for (int i = 0; i < format->precision - len_str; i++)
        append_char(buffer, index, '0');
    }
    uToString(value, buffer, index);
  }
}