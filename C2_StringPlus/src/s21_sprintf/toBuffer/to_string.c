#include "../../s21_sprintf.h"

void intToString(long number, char *buffer, int *index) {
  char temp[1024];
  int count = 0;
  if (number == 0)
    append_char(buffer, index, '0');
  else {
    if (number < 0) {
      append_char(buffer, index, '-');
      number *= -1;
    }
    while (number > 0) {
      temp[count++] = (number % 10) + '0';
      number /= 10;
    }
    for (int i = count - 1; i >= 0; i--) append_char(buffer, index, temp[i]);
  }
  buffer[*index] = '\0';
}

void floatToString(double number, char *buffer, int precision, int *index,
                   Format *format) {
  double factor = pow(10.0, precision);
  number = round(number * factor) / factor;

  long int_part = (long)number;

  if (format->flag_plus && number > 0)
    append_char(buffer, index, '+');
  else if (format->flag_space && number > 0)
    append_char(buffer, index, ' ');

  double float_part =
      (number < 0) ? -1 * (number - int_part) : (number - int_part);
  intToString(int_part, buffer, index);

  if (precision > 0) {
    append_char(buffer, index, '.');
    for (int i = 0; i < precision; i++) {
      float_part *= 10;
      int digit = (int)(float_part + 0.000001);
      append_char(buffer, index, digit + '0');
      float_part -= digit;
    }
  }

  buffer[*index] = '\0';
}

void uToString(unsigned long int number, char *buffer, int *index) {
  int count = 0;
  char temp[1024];
  if (number == 0) {
    append_char(buffer, index, '0');
  } else {
    while (number > 0) {
      temp[count++] = (number % 10) + '0';
      number /= 10;
    }

    for (int i = count - 1; i >= 0; i--) append_char(buffer, index, temp[i]);
  }
  buffer[*index] = '\0';
}

int pointerToString(char *buffer, s21_size_t size, void *ptr) {
  if (ptr == s21_NULL) {
    return 1;
  }
  unsigned long address = (unsigned long)ptr;
  int i = size - 1;
  buffer[i] = '\0';

  while (address > 0 && i > 0) {
    int digit = address % 16;
    buffer[--i] = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
    address /= 16;
  }

  if (i > 0) {
    for (int j = 0; j < (int)size - i; j++) {
      buffer[j] = buffer[i + j];
    }
    buffer[size - i - 1] = '\0';
  } else {
    buffer[0] = '\0';
  }
  return 0;
}

void hexToString(unsigned long int num, char *buffer, int *index,
                 bool lower_case) {
  if (num == 0) {
    buffer[(*index)++] = '0';
  } else {
    while (num > 0) {
      unsigned long int digit = num % 16;
      if (lower_case)
        buffer[(*index)++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
      else
        buffer[(*index)++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'A');
      num /= 16;
    }
  }
  buffer[*index] = '\0';
  for (int i = 0; i < (*index) / 2; i++) {
    char temp = buffer[i];
    buffer[i] = buffer[*index - i - 1];
    buffer[*index - i - 1] = temp;
  }
}

void octaToString(char *buffer, int value, int *index) {
  if (value == 0) {
    buffer[(*index)++] = '0';
  } else {
    while (value > 0) {
      buffer[(*index)++] = (value % 8) + 48;
      value = value / 8;
    }
  }
  buffer[*index] = '\0';
  for (int i = 0; i < (*index) / 2; i++) {
    char temp = buffer[i];
    buffer[i] = buffer[*index - i - 1];
    buffer[*index - i - 1] = temp;
  }
}

float eToString(char *str, int *index_str) {
  int sign = 1;
  float res = 0.0;
  float fraction = 1.0;
  if (str[*index_str] == '-') {
    sign = -1;
    (*index_str)++;
  } else if (str[*index_str] == '+') {
    (*index_str)++;
  }
  while (str[*index_str] >= '0' && str[*index_str] <= '9') {
    res = res * 10 + (str[*index_str] - '0');
    (*index_str)++;
  }
  if (str[*index_str] == '.') {
    (*index_str)++;
    while (str[*index_str] >= '0' && str[*index_str] <= '9') {
      fraction = fraction / 10.0;
      res = res + (str[*index_str] - '0') * fraction;
      (*index_str)++;
    }
  }
  res = res * sign;
  int sign_e = 1;
  int exp = 0;
  if (str[*index_str] == 'e' || str[*index_str] == 'E') {
    (*index_str)++;
    if (str[*index_str] == '-') {
      sign_e = -1;
      (*index_str)++;
    } else if (str[*index_str] == '+') {
      (*index_str)++;
    }
    while (str[*index_str] >= '0' && str[*index_str] <= '9') {
      exp = exp * 10 + (str[*index_str] - '0');
      (*index_str)++;
    }
    exp = exp * sign_e;
  }
  while (exp > 0) {
    res = res * 10;
    exp--;
  }
  while (exp < 0) {
    res = res / 10;
    exp++;
  }
  return res;  // далее нужно преобразовать float в string
}