.PHONY: all, clean, lclean, fclean, lfclean, re, lre

NAME = fdf

LIB = libft/libft.a

LIBPRINTF = ft_printf/libftprintf.a

SRC_NAME = 

SRC_PATH = src/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_NAME = $(subst .c,.o,$(SRC_NAME))

OBJ = $(addprefix $(SRC_PATH),$(OBJ_NAME))

CFLAGS = -Wall -Wextra -Werror

XFLAGS = -lmlx -framework AppKit -framework -OpenGL

CC = gcc

$(NAME): $(OBJ)
	make -C libft;
	make -C ft_printf;
	$(CC) $(CFLAGS) -o $(NAME) main.c $(OBJ) $(XFLAGS) $(LIB) $(LIBPRINTF)

all: $(NAME)

clean:
	rm -rfv $(OBJ)

lclean: clean
	make clean -C libft;
	make clean -C ft_printf

fclean: clean
	rm -rfv $(NAME)

lfclean: lclean
	rm -rfv $(NAME)
	make fclean -C libft;
	make fclean -C ft_printf;

re: fclean all

lre: lfclean all
