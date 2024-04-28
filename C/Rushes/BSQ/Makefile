CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c read_file.c analyze_file.c calculate_square.c write_map_error.c write_map.c
all: bsq
bsq: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o bsq
clean:
	rm -f bsq
fclean: clean
re: fclean all