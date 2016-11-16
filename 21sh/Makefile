.PHONY: all, clean, fclean, re

NAME = 21sh

SRC_NAME = main.c canon.c ft_handle.c\
		   signal/signal.c signal/is_signal.c signal/initialize.c\
		   command/read_loop.c command/handle.c command/cursor.c\
		   command/tabulation.c command/recreate.c command/handle_del.c\
		   command/handle_trbl.c command/termcap.c command/rewrite.c\
		   command/termcap_special.c command/insert.c command/save_cursor.c\
		   command/handle_mvwrd.c command/handle_stnd.c command/handle_scrc.c\
		   command/handle_wcp.c command/del.c command/handle_special.c\
		   command/quoting.c command/moove_cursor.c\
		   command/read_noncanonized.c\
		   error/shell_error.c\
		   env/search_env.c

SRC_PATH = src/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_NAME = $(subst .c,.o,$(SRC_NAME))

LIB = ../libft/libft.a

LIBPRINTF = ../ft_printf/libftprintf.a

OBJ = $(addprefix $(SRC_PATH),$(OBJ_NAME))

CFLAGS = -Wall -Wextra -Werror

CC = gcc

$(NAME): $(OBJ)
	make -C ../libft
	make -C ../ft_printf
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB) $(LIBPRINTF) -lncurses

all: $(NAME)

clean:
	make clean -C ../libft
	make clean -C ../ft_printf
	rm -rfv $(OBJ)

fclean: clean
	make fclean -C ../libft
	make fclean -C ../ft_printf
	rm -rfv $(NAME)

re: fclean all
