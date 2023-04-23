NAME = minitalk
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): client server

client: client.c
	$(CC) -o client $(CFLAGS) client.c

server: server.c
	$(CC) -o server $(CFLAGS) server.c
clean:
	rm -f client.o server.o

fclean: clean
	rm -f client server

re: fclean all

.PHONY: all clean fclean re