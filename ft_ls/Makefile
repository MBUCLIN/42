.PHONY: all, clean, lclean, fclean, lfclean, re, lre

NAME = ft_ls

SRC_NAME = alloc.c check.c debug.c del.c error.c initiate.c option.c \
		   get_info.c get.c get_line.c get_max_len.c minor_major.c \
		   get_node.c insert.c print.c read.c

SRC_PATH = src/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_NAME = $(subst .c,.o,$(SRC_NAME))

LIB = ../libft/libft.a

LIBFTPRINTF = ../ft_printf/libftprintf.a

OBJ = $(addprefix $(SRC_PATH),$(OBJ_NAME))

CFLAGS = -Wall -Wextra -Werror

CC = gcc

$(NAME): $(OBJ)
	make -C ../libft;
	make -C ../ft_printf;
	$(CC) $(CFLAGS) -o $(NAME) main.c $(OBJ) $(LIB) $(LIBFTPRINTF)

all: $(NAME)

clean:
	rm -rfv $(OBJ)

lclean: clean
	make clean -C ../libft;
	make clean -C ../ft_printf;

fclean: clean
	rm -rfv $(NAME)

lfclean: fclean
	make fclean -C ../libft;
	make fclean -C ../ft_printf;

re: fclean all

lre: lfclean all
