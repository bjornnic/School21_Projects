#include "../../s21_sprintf.h"
int s21_sprintf_parcer(const char **strFormat, Format *format, va_list args) {
  // printf("yess");
  while (**strFormat == '-' || **strFormat == '+' || **strFormat == ' ' ||
         **strFormat == '0' || **strFormat == '#')  // паршу флаги
  {
    if (**strFormat == '-') format->flag_minus = true;
    if (**strFormat == '+') format->flag_plus = true;
    if (**strFormat == ' ') format->flag_space = true;
    if (**strFormat == '0') format->flag_null = true;
    if (**strFormat == '#') format->flag_hash = true;
    (*strFormat)++;
  }
  if (**strFormat == '*') {
    format->width = va_arg(args, int);
    (*strFormat)++;
  }

  while (**strFormat >= '0' && **strFormat <= '9' &&
         **strFormat != '.')  // паршу ширину
  {
    format->width = (format->width * 10) + (**strFormat - '0');
    (*strFormat)++;
  }
  if (**strFormat == '.')  // паршу точность
  {
    format->prec = true;
    (*strFormat)++;
    format->precision = 0;
    if (**strFormat == '*') {
      format->precision = va_arg(args, int);
      (*strFormat)++;
    }
    while (**strFormat >= '0' && **strFormat <= '9') {
      format->precision = (format->precision * 10) + (**strFormat - '0');
      (*strFormat)++;
    }
  }
  while (**strFormat == 'h' || **strFormat == 'l' ||
         **strFormat == 'L')  // паршу флаги
  {
    if (**strFormat == 'h')
      format->length = 'h';
    else if (**strFormat == 'l')
      format->length = 'l';
    else if (**strFormat == 'L')
      format->length = 'L';
    (*strFormat)++;
  }
  // printf("%d\n", format->width);
  // if (format->flag_null) printf("null\n");
  return **strFormat;
}
