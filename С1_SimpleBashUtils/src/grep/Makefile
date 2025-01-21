FLAGS = -std=c11 -Wall -Wextra -Werror
TARGET = s21_grep
SRC = s21_grep.c
HEADERS = s21_grep.h

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	gcc $(FLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

rebuild: clean all