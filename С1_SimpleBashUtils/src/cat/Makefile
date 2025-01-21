FLAGS = -std=c11 -Wall -Wextra -Werror
TARGET = s21_cat
SRC = s21_cat.c
HEADERS = s21_cat.h

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	gcc $(FLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

rebuild: clean all