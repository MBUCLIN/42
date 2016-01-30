#include "../includes/ft_printf.h"

int		ft_is_flags(int c)
{
	if (c == '#' || c == ' ' || c == '-' || c == '+' || c == '0')
		return (c);
	return (0);
}
