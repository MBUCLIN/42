#include "../includes/ft_printf.h"

int		ft_isconvc(int c)
{
	if (c == 'c' || c == 's' || c == '%' ||\
		c == 'S' || c == 'C' || c == 'p')
		return (1);
	return (0);
}
