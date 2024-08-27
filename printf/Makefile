NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils.c


#This is the command to create a static library archive
AR = ar rcs

# This is the compiler to use
CC = cc

# These are the flags to use during compilation
CFLAGS = -Wall -Wextra -Werror

# This is the list of object files to compile ${SRCS:.c=.o} will replace the .c with .o
OBJS = ${SRCS:.c=.o}

RM		= rm -f

#All is the first target. It is the default target. So if you just type make, it will run this target
all: $(NAME)

# This is the target to create the static library archive ${NAME} from the object files ${OBJS}
$(NAME): ${OBJS}
	$(AR) $@ $? 

#This is the target to compile the object files. The $< is the first dependency. The -c flag is to compile the file without linking  -o is to specify the output file name and $@ is the target name
# This rule says that for each file in the list of object files, compile it using the compiler and flags
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

#This target will remove the object files and the bonus object files. .bonus is removed to allow the bonus to be compiled again.
clean:
	${RM} $(OBJS)

#This .bonus target will create the static library archive from the object files and the bonus object files. It will then create a file called .bonus to prevent the bonus from being compiled again.
#Touch .bonus is used to create the file .bonus if it does not exist. If it does exist, it will update the timestamp of the file to the current time.

# Fclean will remove the static library archive and the object files
fclean: clean
	${RM} $(NAME)

# Re will remove the static library archive and the object files and then recompile the library
re: fclean all 
# This is to tell make that clean, fclean, re, and bonus are not files. This will prevent make from confusing them with files of the same name
.PHONY: all clean fclean re 