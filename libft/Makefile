# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dakcakoc <dakcakoce@student.hive.fi>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 10:32:48 by dakcakoc          #+#    #+#              #
#    Updated: 2024/05/10 13:19:06 by dakcakoc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_itoa.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
       ft_isdigit.c ft_isprint.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_putchar_fd.c \
       ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_strlen.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_strrchr.c ft_strdup.c ft_strjoin.c ft_split.c ft_strmapi.c\
       ft_tolower.c ft_toupper.c ft_calloc.c ft_strnstr.c ft_strchr.c ft_substr.c ft_strtrim.c ft_striteri.c \

BONUS =	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
		ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstmap_bonus.c \
	   
HEADER = libft.h

#This is the command to create a static library archive
AR = ar rcs

# This is the compiler to use
CC = cc

# These are the flags to use during compilation
CFLAGS = -Wall -Wextra -Werror

# This is the list of object files to compile ${SRCS:.c=.o} will replace the .c with .o
OBJS = ${SRCS:.c=.o}

# This is the list of bonus object files to compile ${BONUS:.c=.o} will replace the .c with .o
BONUS_OBJS = $(BONUS:.c=.o)

#All is the first target. It is the default target. So if you just type make, it will run this target
all: $(NAME)

# This is the target to create the static library archive ${NAME} from the object files ${OBJS}
$(NAME): ${OBJS}
	$(AR) $@ $? 

#This is the target to compile the object files. The $< is the first dependency. The -c flag is to compile the file without linking  -o is to specify the output file name and $@ is the target name
# This rule says that for each file in the list of object files, compile it using the compiler and flags
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# This bonus target will compile the bonus object files and create the static library archive. .bonus is a file that is created when the bonus is compiled. 
# This is to prevent the bonus from being compiled again if it has already been compiled
bonus: .bonus

#This target will remove the object files and the bonus object files. .bonus is removed to allow the bonus to be compiled again.
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -f .bonus

#This .bonus target will create the static library archive from the object files and the bonus object files. It will then create a file called .bonus to prevent the bonus from being compiled again.
#Touch .bonus is used to create the file .bonus if it does not exist. If it does exist, it will update the timestamp of the file to the current time.
.bonus:	$(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
	touch .bonus

# Fclean will remove the static library archive and the object files
fclean: clean
	rm -f $(NAME)

# Re will remove the static library archive and the object files and then recompile the library
re: fclean all bonus
# This is to tell make that clean, fclean, re, and bonus are not files. This will prevent make from confusing them with files of the same name
.PHONY: all clean fclean re bonus

