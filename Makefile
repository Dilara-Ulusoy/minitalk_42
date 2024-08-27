SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
FFLAGS = -I libft -I printf
COMPILE = $(CC) $(CFLAGS)
SRCS = client.c server.c utils.c
OBJ = $(SRCS:%.c=%.o)

#******************************************************************************#

all: $(SERVER) $(CLIENT)

$(SERVER): server.o utils.o libft/libft.a printf/libftprintf.a
	$(COMPILE) server.o utils.o libft/libft.a printf/libftprintf.a -o $@

$(CLIENT): client.o utils.o libft/libft.a printf/libftprintf.a
	$(COMPILE) client.o utils.o libft/libft.a printf/libftprintf.a -o $@

%.o: %.c
	$(COMPILE) $< -c -o $@

libft/libft.a:
	$(MAKE) -C libft

printf/libftprintf.a:
	$(MAKE) -C printf

#******************************************************************************#

clean:
	/bin/rm -f $(OBJ)
	$(MAKE) -C libft clean
	$(MAKE) -C printf clean

fclean: clean
	/bin/rm -f $(SERVER) $(CLIENT)
	$(MAKE) -C libft fclean
	$(MAKE) -C printf fclean

re: fclean all

#******************************************************************************#
.PHONY: all clean fclean re
#******************************************************************************#
