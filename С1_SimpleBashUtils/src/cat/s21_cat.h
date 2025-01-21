#ifndef S21_CAT_H
#define S21_CAT_H
#define _GNU_SOURCE

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct arguments {
  int b, n, s, E, T, v;
} arguments;

arguments argument_parser(int argc, char** argv, int* first_file_index);
void process_files(arguments* arg, int file_count, char** files);
void process_file(arguments* arg, const char* filename);
void outline(arguments* arg, char* line, int read, int* line_count,
             int* empty_count);
char v_output(char ch);

#endif