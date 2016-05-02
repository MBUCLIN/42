NAME = ft_ls

SRC_NAME = alloc.c check.c debug.c del.c error.c initiate.c option.c

SRC_PATH = src/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_NAME = $(subst .c,.o,$(SRC_NAME))

LIB = libft/libft.a

LIBFTPRINTF = ft_printf/libftprintf.a

OBJ = $(addprefix $(SRC_PATH),$(OBJ_NAME))

CFLAGS = -Wall -Wextra -Wall

CC = gcc

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) main.c $(OBJ) $(LIB) $(LIBFTPRINTF)

all: $(NAME)

clean:
	rm -rfv $(OBJ)

fclean: clean
	rm -rfv $(NAME)

re: fclean all
