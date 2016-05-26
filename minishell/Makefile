.PHONY: all clean lclean fclean lfclean re lre

NAME = minishell

LIB = libft/libft.a

LIBFTPRINTF = ft_printf/libftprintf.a

SRC_NAME = initiate.c prompt.c read_command.c command.c get.c

SRC_PATH = src/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_NAME = $(subst .c,.o,$(SRC_NAME))

OBJ = $(addprefix $(SRC_PATH),$(OBJ_NAME))

CFLAGS = -Wall -Wextra -Werror

CC = gcc

$(NAME): $(OBJ)
	make -C libft;
	make -C ft_printf;
	$(CC) $(CFLAGS) -o $(NAME) main.c $(OBJ) $(CFLAGS) $(LIB) $(LIBFTPRINTF)

all: $(NAME)

clean:
	rm -rfv $(OBJ)

lclean: clean
	make clean -C libft;
	make clean -C ft_printf;

fclean: clean
	rm -rfv $(NAME)

lfclean: lclean
	rm -rfv $(NAME)
	make fclean -C libft;
	make fclean -C ft_printf;

re: fclean all

lre: lfclean all
