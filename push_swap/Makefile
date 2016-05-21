.PHONY: all, clean, fclean, re

NAME = push_swap

SRC_NAME = initiate.c del.c option.c parseur.c put_pile.c command.c\
		   sort.c inteligent_sort.c call_command.c cpy.c distance_sort.c\
		   check.c use.c get.c push_swap.c rotate.c command_list.c search.c\
		   condition.c debug.c choose_moove.c treat_info.c make_moov.c count.c\
		   info.c big_stack_algo.c push_a_order.c push_mediane.c apply_option.c\
		   make_the_action.c

SRC_PATH = src/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_NAME = $(subst .c,.o,$(SRC_NAME))

LIB = libft/libft.a

LIBFTPRINTF = ft_printf/libftprintf.a

OBJ = $(addprefix $(SRC_PATH),$(OBJ_NAME))

CFLAGS = -Wall -Wextra -Werror

CC = gcc

$(NAME): $(OBJ)
	make -C libft;
	make -C ft_printf;
	$(CC) $(CFLAGS) -o $(NAME) main.c $(OBJ) $(LIB) $(LIBFTPRINTF)

all: $(NAME)

clean:
	make clean -C libft;
	make clean -C ft_printf;
	rm -rfv $(OBJ)

fclean: clean
	make fclean -C libft;
	make fclean -C ft_printf;
	rm -rfv $(NAME)

re: fclean all
