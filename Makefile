FILES = server.c \
		client.c \

BONUS_FILES =	client_bonus.c \
				server_bonus.c \

FtoO	= $(FILES:.c=.o)

CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM		=	rm -f

LIBFT = libft/libft.a

all:	server client

server:  server.o $(LIBFT) 
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@

client:   client.o $(LIBFT) 
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@

$(LIBFT):
	make -C ./libft

client_bonus: client_bonus.o $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@

server_bonus: server_bonus.o $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $^ -o $@	

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make fclean -C libft
	$(RM) $(FtoO) client_bonus.o server_bonus.o

fclean: clean
	make fclean -C libft
	$(RM) server client $(FtoO)
	$(RM) client_bonus server_bonus

re: fclean all

bonus: client_bonus server_bonus

.PHONY: all clean fclean re bonus