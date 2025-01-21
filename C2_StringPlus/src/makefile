.PHONY: all clean rebuild
SHELL := /bin/bash

FLAGS = -Wall -Werror -Wextra -std=c11
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
CHECK_FLAGS = $(shell pkg-config --cflags --libs check) -lpthread -lm

DIRS = -Is21_string_functions -Is21_sprintf

SRC = $(wildcard s21_string_functions/s21_*.c) $(wildcard s21_sprintf/s21_*.c) $(wildcard s21_sprintf/format/*.c) $(wildcard s21_sprintf/parcer/s21_*.c) $(wildcard s21_sprintf/toBuffer/*.c)
OBJ = $(SRC:.c=.o)

TEST_SRC1 = s21_string_functions/test_s21_string.c
TEST_OBJ = $(TEST_SRC:.c=.o)
TEST_SRC2 = s21_string_functions/test_s21.c
LIB = s21_string.a

all: $(LIB) test gcov_report

$(LIB): $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

test: $(OBJ) $(TEST_SRC)
	gcc $(FLAGS) $(GCOV_FLAGS) -o test $(TEST_SRC1) $(LIB) $(CHECK_FLAGS)
	./test

gcov_report: test
	./test
	lcov -c -d . -o coverage.info
	genhtml coverage.info -o gcov_report

%.o: %.c
	gcc  $(FLAGS) $(INCLUDE_DIRS) -c $< -o $@

clean:
	rm -rf s21_string_functions/*.o s21_sprintf/*.o s21_sprintf/format/*.o s21_sprintf/parcer/*.o s21_sprintf/toBuffer/*.o *.o *.a test *.gcda *.gcno *.info report gcov* *.gcov

rebuild: clean all