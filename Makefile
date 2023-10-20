CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

SERVER = server
CLIENT = client

SERVER_SRCS = src/server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_SRCS = src/client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

LIBFT = libft/libft.a

$(LIBFT):
	make -C libft

all: $(SERVER) $(CLIENT)

$(SERVER): $(LIBFT) $(SERVER_OBJS) 
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) -Llibft -lft

$(CLIENT): $(LIBFT) $(CLIENT_OBJS) 
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJS) -Llibft -lft

clean:
	cd libft && make clean
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	cd libft && make fclean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re