#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

typedef unsigned long s21_size_t;

typedef struct {
  bool flag_plus;
  bool flag_minus;
  bool flag_space;
  bool flag_hash;
  bool flag_null;
  int width;
  int precision;
  bool prec;
  int length;
} Format;

int s21_sprintf_parcer(
    const char **strFormat, Format *format,
    va_list args);  // парсит формат, возвращает спецификатор,
                    // остальное записывает в структуру Format
void s21_sprintf_specifier(
    char *buffer, char specifier, int *index, va_list args,
    Format *format);  // Отвечает за вызов тех или иных функций при тех или иных
                      // спецификаторах

void append_char(char *buffer, int *index,
                 char c);  // добавляет символ в конец буффера и считает
                           // количество переданных символов
void append_string(char *buffer, int *index,
                   const char *str);  // то же самое, только для строк

void intToString(long number, char *buffer,
                 int *index);  // переводит числа в строки
void floatToString(
    double number, char *buffer, int precision, int *index,
    Format *format);  // переводит числа с плавающей точкой в строки
void uToString(unsigned long int number, char *buffer,
               int *index);  // переводит беззнаковые числа в строки +
                             // обрабатывает отрицательные значения
int pointerToString(char *buffer, s21_size_t size,
                    void *ptr);  // переводит указатель в строку
void hexToString(unsigned long int num, char *buffer, int *index,
                 bool lowe_case);  // переводит из инта в шестнадцатеричное
                                   // представление, потом в строку
void negative_unsigned(int *num,
                       char length);  // обработка отрицательных беззнаковых
                                      // чисел в зависимости от длины
void processHex(char specifier, va_list args, char *buffer, int *index,
                Format *format);  // вспомогательная функция для обработки %o
void octaToString(char *buffer, int value,
                  int *index);  // переводит из инта в шестнадцатеричное
                                // представление, потом в строку
float eToString(char *str, int *index_str);

void int_format(char *buffer, int value, int *index, Format *format);
void string_format(char *buffer, const char *value, int *index,
                   Format *format);  // обработка спецификатора строк
void float_format(
    char *buffer, double value, int *index,
    Format *format);  // обработка спецификатора чисел с плавающей запятой
void char_format(char *buffer, char value, int *index,
                 Format *format);  // обработка спецификатора символов
void unsigned_int_format(
    char *buffer, unsigned long int value, int *index,
    Format *format);  // обработка спецификатора беззнаковых чисел

int s21_sprintf(char *buffer, const char *strFormat, ...);

#endif
