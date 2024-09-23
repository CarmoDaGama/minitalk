NAME = server client
CC = cc
CFLAGS = -Wall -Wextra -Werror
FT_PRINTF = ft_printf
OBJS_FILES = minitalk.o

all: $(NAME)

$(NAME): $(OBJS_FILES)
	make -C $(FT_PRINTF) 
	$(CC) $(CFLAGS) $(OBJS_FILES) -o server server.c $(FT_PRINTF)/libftprintf.a
	$(CC) $(CFLAGS) $(OBJS_FILES) -o client client.c $(FT_PRINTF)/libftprintf.a


clean:
	rm -f $(OBJS_FILES)
	make -C $(FT_PRINTF) clean
	
fclean: clean
	rm -f server client $(FT_PRINTF)/libftprintf.a

re: fclean all