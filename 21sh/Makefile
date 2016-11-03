.PHONY: all clean fclean lclean lfclean re
NAME = 21sh

PATH = src/

SRC_NAME = main.c canon.c \
		   signal/signal.c signal/is_signal.c \
		   command/read_loop.c command/handle.c command/cursor.c \
		   command/tabulation.c command/recreate.c command/handle_del.c \
		   command/handle_trbl.c command/termcap.c command/rewrite.c \
		   command/termcap_special.c \
		   error/shell_error.c \
		   env/search_env.c
OBJ_NAME = $(subst .c,.o,$(SRC_NAME))

SRC = $(addprefix $(PATH),$(SRC_NAME))
OBJ = $(addprefix $(PATH),$(OBJ_NAME))
LIB = ../libft/libft.a
LIBPRINTF = ../ft_printf/libftprintf.a

CFLAGS = -Wall -Wextra -Werror
CC = gcc

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB) $(LIBPRINTF) -lncurses

all: $(NAME)

clean:
	rm -rfv $(OBJ)

fclean: clean
	rm -rfv $(NAME)

re: fclean all
