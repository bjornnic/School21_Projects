#include "s21_cat.h"

arguments argument_parser(int argc, char** argv, int* first_file_index) {
  arguments arg = {0};
  struct option long_options[] = {{"number", no_argument, NULL, 'n'},
                                  {"number-nonblank", no_argument, NULL, 'b'},
                                  {"squeeze-blank", no_argument, NULL, 's'},
                                  {0, 0, 0, 0}};
  int opt;
  while ((opt = getopt_long(argc, argv, "bneETtsv", long_options, NULL)) !=
         -1) {
    switch (opt) {
      case 'b':
        arg.b = 1;
        break;
      case 'n':
        arg.n = 1;
        break;
      case 's':
        arg.s = 1;
        break;
      case 'E':
        arg.E = 1;
        break;
      case 'e':
        arg.E = 1;
        arg.v = 1;
        break;
      case 'T':
        arg.T = 1;
        break;
      case 't':
        arg.T = 1;
        arg.v = 1;
        break;
      case 'v':
        arg.v = 1;
        break;
      case '?':
        exit(1);
    }
  }
  *first_file_index = optind;
  return arg;
}

void process_files(arguments* arg, int file_count, char** files) {
  for (int i = 0; i < file_count; i++) {
    process_file(arg, files[i]);
  }
}

void process_file(arguments* arg, const char* filename) {
  FILE* f = fopen(filename, "r");
  if (!f) {
    perror(filename);
  }

  char* line = NULL;
  size_t memline = 0;
  int read = 0;
  int line_count = 1;
  int empty_count = 0;

  while ((read = getline(&line, &memline, f)) != -1) {
    outline(arg, line, read, &line_count, &empty_count);
  }

  free(line);
  fclose(f);
}

void outline(arguments* arg, char* line, int read, int* line_count,
             int* empty_count) {
  if (line[0] == '\n') {
    (*empty_count)++;
  } else {
    *empty_count = 0;
  }

  if (arg->s && *empty_count > 1) return;

  if (arg->b && line[0] != '\n') {
    printf("%6d\t", (*line_count)++);
  } else if (arg->n && !arg->b) {
    printf("%6d\t", (*line_count)++);
  }

  for (int i = 0; i < read; i++) {
    if (arg->T && line[i] == '\t') {
      printf("^I");
    } else {
      if (arg->E && line[i] == '\n') putchar('$');
      if (arg->v) line[i] = v_output(line[i]);
      putchar(line[i]);
    }
  }
}

char v_output(char ch) {
  if (ch == '\n' || ch == '\t') return ch;
  if (ch > 0 && ch <= 31) {
    putchar('^');
    ch += 64;
  } else if (ch == 127) {
    putchar('^');
    ch = '?';
  }
  return ch;
}

int main(int argc, char* argv[]) {
  int first_file_index = 0;
  arguments arg = argument_parser(argc, argv, &first_file_index);

  if (first_file_index >= argc) {
    fprintf(stderr, "Используйте: %s <опция> <название_файла>\n", argv[0]);
    exit(1);
  }

  process_files(&arg, argc - first_file_index, &argv[first_file_index]);
  return 0;
}