#include "../../s21_sprintf.h"

void s21_sprintf_specifier(char *buffer, char specifier, int *index,
                           va_list args, Format *format) {
  switch (specifier) {
    case 'c': {
      char c = (char)va_arg(args, int);
      char_format(buffer, c, index, format);
      break;
    }
    case 'd': {
      int i = va_arg(args, int);
      int_format(buffer, i, index, format);
      break;
    }
    case 'f': {
      long double f = 0;
      if (format->length == 'L')
        f = va_arg(args, long double);
      else
        f = va_arg(args, double);
      float_format(buffer, f, index, format);
      break;
    }
    case 's': {
      const char *str = va_arg(args, const char *);
      string_format(buffer, str, index, format);
      break;
    }
    case 'u': {
      int u = va_arg(args, int);
      negative_unsigned(&u, format->length);
      unsigned_int_format(buffer, (unsigned long)u, index, format);
      break;
    }
    case 'p': {
      void *pointer = va_arg(args, void *);
      char temp[1024];
      if (pointerToString(temp, 1024, pointer) != 1) {
        append_string(buffer, index, "0x");
        format->width -= 2;
        string_format(buffer, temp, index, format);
      } else
        append_string(buffer, index, "(nil)");

      break;
    }
    case 'x':
    case 'X': {
      processHex(specifier, args, buffer, index, format);
      break;
    }
    case 'o': {
      int len = 0;
      char temp[1024];
      int o = va_arg(args, int);
      negative_unsigned(&o, format->length);
      octaToString(temp, o, &len);
      if (format->flag_hash) {
        append_string(buffer, index, "0");
        format->width -= 2;
      }
      string_format(buffer, temp, index, format);
      break;
    }
    case 'e':
    case 'E': {
      processHex(specifier, args, buffer, index, format);
      break;
    }
    default: {
      {
        append_char(buffer, index, specifier);
        break;
      }
    }
  }
}

void negative_unsigned(int *num, char length) {
  if (*num < 0) {
    if (length == 0) {
      (*num) += 4294967296;
    } else if (length == 'h') {
      *num = (unsigned short)((*num) + 65536);
    } else if (length == 'l') {
      *num = (unsigned long)((*num) + 18446744073709551615ULL + 1);
    }
  }
}

void processHex(char specifier, va_list args, char *buffer, int *index,
                Format *format) {
  char temp[1024];
  int len = 0;
  if (specifier == 'x') {
    int num = va_arg(args, int);
    negative_unsigned(&num, format->length);
    hexToString(num, temp, &len, true);
    if (format->flag_hash) {
      append_string(buffer, index, "0x");
      format->width -= 2;
    }
  } else if (specifier == 'X') {
    long int num = va_arg(args, long int);
    negative_unsigned((int *)&num, format->length);
    hexToString(num, temp, &len, false);
    if (format->flag_hash) {
      append_string(buffer, index, "0X");
      format->width -= 2;
    }
  }
  if (format->flag_minus && format->prec) {
    for (int i = 0; i < format->precision - len; i++)
      append_char(buffer, index, '0');
  }

  string_format(buffer, temp, index, format);
}