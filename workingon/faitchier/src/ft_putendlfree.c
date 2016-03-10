#include "../includes/ft_printf.h"

void		ft_putendlfree(char *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	free(s);
	s = NULL;
}
