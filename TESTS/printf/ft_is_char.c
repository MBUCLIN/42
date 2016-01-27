#include "ft_printf.c"

int		ft_is_char(int c)
{
	if (c == 'c' || c == 's')
		return (c);
	return (0);
}
