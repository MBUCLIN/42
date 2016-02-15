NAME = libftprintf.a

SRC_NAME = ft_apply_pandw.c \
		   ft_apply_flagsi.c \
		   ft_apply_integc.c \
		   ft_apply_conv.c \
		   ft_isconvc.c \
		   ft_isconvi.c \
		   ft_isconv.c \
		   ft_isflag.c \
		   ft_iswidth.c \
		   ft_ispreci.c \
		   ft_islm.c \
		   ft_getpreci.c \
		   ft_getwidth.c \
		   ft_getadj.c \
		   ft_get_lm.c \
		   ft_check_conv.c \
		   ft_printf.c

SRC_PATH = src/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

FLAGS = -Wall -Wextra -Werror

$(NAME):
	@mkdir $(OBJ_PATH)
	@gcc -c $(FLAGS) $(SRC)
	@mv $(OBJ_NAME) $(OBJ_PATH)
	@ar rc $(NAME) $(OBJ) libft/*.o
	@echo "\033[32mCreation lib done!\033[0m"

all: $(NAME)

clean:
	@rm -Rfv $(OBJ_PATH)

fclean: clean
	@rm -Rfv $(NAME)

re: fclean all
