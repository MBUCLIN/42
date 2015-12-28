NAME = fillit
LIB = ../libft/libft.a

SRC = checkvalidity.c \
	  createmap.c \
	  createsample.c \
	  solv_check.c \
	  main.c \
	  solve_fillit.c \
	  read.c \
	  lstedit.c \
	  moove_tetri.c

FLAGS = -Wall -Wextra -Werror

$(NAME):
	gcc -o $(NAME) $(SRC) $(LIB)

all: $(NAME)

fclean:
	rm -f $(NAME)

backupclean:
	rm -f .*.c
	rm -f *~

re: fclean all
