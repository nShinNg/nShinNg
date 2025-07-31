CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = print_groups

all: $(NAME)

$(NAME): print_groups.c
	$(CC) $(CFLAGS) -o $(NAME) print_groups.c

clean:
	rm -f $(NAME)

test_root:
	FT_USER=root ./$(NAME)

test_daemon:
	FT_USER=daemon ./$(NAME)

.PHONY: all clean test_root test_daemon