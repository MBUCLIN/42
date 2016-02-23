NAME = libft.a

PC = ft_memset.c \
	 ft_memalloc.c \
	 ft_memcpy.c \
	 ft_memccpy.c \
	 ft_memmove.c \
	 ft_memchr.c \
	 ft_memdel.c \
	 ft_strdel.c \
	 ft_bzero.c \
	 ft_strclr.c \
	 ft_putchar.c \
	 ft_putchar_fd.c \
	 ft_putstr.c \
	 ft_putstr_fd.c \
	 ft_putendl.c \
	 ft_putendl_fd.c \
	 ft_putnbr.c \
	 ft_putnbr_fd.c \
	 ft_striter.c \
	 ft_striteri.c \
	 ft_strlen.c \
	 ft_strrev.c \
	 ft_tolower.c \
	 ft_toupper.c \
	 ft_isalpha.c \
	 ft_isdigit.c \
	 ft_isalnum.c \
	 ft_isascii.c \
	 ft_isprint.c \
	 ft_atoi.c \
	 ft_memcmp.c \
	 ft_strcmp.c \
	 ft_strncmp.c \
	 ft_strequ.c \
	 ft_strnequ.c \
	 ft_itoa.c \
	 ft_strnew.c \
	 ft_strcat.c \
	 ft_strncat.c \
	 ft_strcpy.c \
	 ft_strncpy.c \
	 ft_strchr.c \
	 ft_strrchr.c \
	 ft_strdup.c \
	 ft_strstr.c \
	 ft_strnstr.c \
	 ft_strsub.c \
	 ft_strsub.c \
	 ft_strmap.c \
	 ft_strmapi.c \
	 ft_strjoin.c \
	 ft_strtrim.c \
	 ft_strsplit.c \
	 ft_strlcat.c \
	 ft_lstnew.c \
	 ft_lstdelone.c \
	 ft_lstdel.c \
	 ft_lstadd.c \
	 ft_lstiter.c \
	 ft_lstmap.c \
	 ft_putnbrbase.c \
	 ft_atoibase.c \
	 ft_itoabase.c \
	 ft_tabdel.c \
	 ft_puttab.c \
	 ft_strjoinfree.c \
	 ft_strjoindfree.c \
	 ft_sitoa.c \
	 ft_sitoabase.c \
	 ft_strmidadd.c \
	 get_next_line.c

PO = ft_memset.o \
	 ft_memalloc.o \
	 ft_memcpy.o \
	 ft_memccpy.o \
	 ft_memmove.o \
	 ft_memchr.o \
	 ft_memdel.o \
	 ft_strdel.o \
	 ft_bzero.o \
	 ft_strclr.o \
	 ft_putchar.o \
	 ft_putchar_fd.o \
	 ft_putstr.o \
	 ft_putstr_fd.o \
	 ft_putendl.o \
	 ft_putendl_fd.o \
	 ft_putnbr.o \
	 ft_putnbr_fd.o \
	 ft_striter.o \
	 ft_striteri.o \
	 ft_strlen.o \
	 ft_strrev.o \
	 ft_tolower.o \
	 ft_toupper.o \
	 ft_isalpha.o \
	 ft_isdigit.o \
	 ft_isalnum.o \
	 ft_isascii.o \
	 ft_isprint.o \
	 ft_atoi.o \
	 ft_memcmp.o \
	 ft_strcmp.o \
	 ft_strncmp.o \
	 ft_strequ.o \
	 ft_strnequ.o \
	 ft_itoa.o \
	 ft_strnew.o \
	 ft_strcat.o \
	 ft_strncat.o \
	 ft_strncpy.o \
	 ft_strcpy.o \
	 ft_strchr.o \
	 ft_strrchr.o \
	 ft_strdup.o \
	 ft_strstr.o \
	 ft_strnstr.o \
	 ft_strsub.o \
	 ft_strmap.o \
	 ft_strmapi.o \
	 ft_strjoin.o \
	 ft_strtrim.o \
	 ft_strsplit.o \
	 ft_strlcat.o \
	 ft_lstnew.o \
	 ft_lstdelone.o \
	 ft_lstdel.o \
	 ft_lstadd.o \
	 ft_lstiter.o \
	 ft_lstmap.o \
	 ft_putnbrbase.o \
	 ft_atoibase.o \
	 ft_itoabase.o \
	 ft_tabdel.o \
	 ft_puttab.o \
	 ft_strjoinfree.o \
	 ft_strjoindfree.o \
	 ft_sitoa.o \
	 ft_sitoabase.o \
	 ft_strmidadd.o \
	 get_next_line.o

FLAGS = -Wall -Wextra -Werror

$(NAME):
	gcc -c $(FLAGS) $(PC)
	ar rc $(NAME) $(PO)

all: $(NAME)

clean:
	rm -f $(PO)

fclean: clean
	rm -f $(NAME)

re: fclean all
