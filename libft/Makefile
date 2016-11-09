.PHONY: all, clean, fclean, re

NAME = libft.a

SRC_NAME = ft_exit.c ft_memset.c ft_handle.c ft_memalloc.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	 ft_memchr.c ft_memdel.c ft_strdel.c ft_bzero.c ft_strclr.c ft_putchar.c ft_putchar_fd.c \
	 ft_putstr.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
	 ft_striter.c ft_striteri.c ft_strlen.c ft_tolower.c ft_toupper.c ft_isalpha.c ft_isdigit.c \
	 ft_isalnum.c ft_isascii.c ft_isstrascii.c ft_isprint.c ft_isoption.c ft_atoi.c ft_memcmp.c \
	 ft_isblank.c ft_strcmp.c ft_strncmp.c ft_strequ.c ft_strnequ.c ft_itoa.c ft_strnew.c \
	 ft_strcat.c ft_strncat.c ft_strcpy.c ft_strncpy.c ft_strchr.c ft_strrchr.c ft_strdup.c \
	 ft_strstr.c ft_strnstr.c ft_strsub.c ft_strsub.c ft_strmap.c ft_strmapi.c ft_strjoin.c \
	 ft_strtrim.c ft_strsplit.c ft_strlcat.c ft_lstlen.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	 ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_imgcpy.c ft_putnbrbase.c ft_atoibase.c ft_itoabase.c \
	 ft_tabdel.c ft_puttab.c ft_strjoinfree.c ft_strjoindfree.c ft_sitoa.c ft_sitoabase.c ft_strmidadd.c \
	 get_next_line.c ft_satoi.c ft_chrnotoption.c ft_deltabstr.c ft_strncadd.c ft_nlen.c ft_strsubfree.c \
	 ft_islexisort.c ft_isrevlexisort.c ft_lstaddend.c ft_tabstrlen.c ft_isstrdigit.c ft_fill_data.c \
	 ft_swap.c ft_srchenv.c ft_strnchr.c ft_tabstrdup.c ft_lsttotabstrfree.c ft_delstrcontent.c \
	 ft_deltabswapstr.c ft_swaptabstr.c ft_skpblk.c ft_addstrtotab.c ft_putlst.c ft_chgvalue.c \
	 ft_creadir.c ft_tabstrsrch.c ft_isempty.c ft_lstindex.c ft_treatquote.c ft_substrc.c \
	 ft_rpcstr.c ft_strisblank.c ft_artol.c ft_writechar.c

PATH = ./
SRC = $(addprefix $(PATH),$(SRC_NAME))
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(PATH),$(OBJ_NAME))


CFLAGS = -Wall -Wextra -Werror
CC = gcc

$(NAME): $(OBJ)
	$(CC) -c $(FLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
