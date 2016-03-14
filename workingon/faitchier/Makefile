.PHONY: all, clean, fclean, re

NAME = libftprintf.a

SRC_PATH = src/

SRC_NAME = ft_apply_charc.c ft_apply_conv.c ft_apply_convp.c \
		   ft_apply_flagsi.c ft_apply_number.c ft_apply_pandw.c \
		   ft_apply_wchar.c ft_apply_widtchar.c ft_apply_wint.c \
		   ft_atoibasefree.c ft_atoi.c ft_checkconv.c ft_convoct.c \
		   ft_getadj.c ft_getlen.c ft_get_lm.c ft_getmask.c ft_putendl.c\
		   ft_get_nbits.c ft_get_noct.c ft_getoct.c ft_getpreci.c ft_putendlfree.c\
		   ft_getwidth.c ft_isconv.c ft_isconvc.c ft_isconvi.c ft_isdigit.c \
		   ft_memcpy.c ft_memset.c ft_printf.c ft_sitoabase.c ft_getconv.c\
		   ft_sitoa.c ft_strdup.c ft_strdupfree.c ft_string_len.c ft_strjoin.c \
		   ft_strjoindfree.c ft_strjoinprintf.c ft_strlen.c ft_strmidadd.c \
		   ft_strrev.c ft_strsub.c ft_strsubfree.c ft_isunsigned.c ft_strdupprintf.c \
		   ft_itoa.c ft_itoabase.c ft_apply_int.c ft_carchr.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

FLAGS = -Wall -Wextra -Werror

$(NAME):
	@mkdir $(OBJ_PATH)
	@gcc -c $(FLAGS) $(SRC)
	@mv $(OBJ_NAME) $(OBJ_PATH)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[32mLib has been created!\033[0m"

all: $(NAME)

clean:
	@rm -Rfv $(OBJ_PATH)

fclean: clean
	@rm -Rfv $(NAME)

re: fclean all
