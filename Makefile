CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

SRC= mastermind.c 
OBJ= mastermind.o
TARGET= mastermind

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all