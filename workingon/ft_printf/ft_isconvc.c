#include "ft_printf.h"

int		ft_isconvc(int c)
{
	if (c == 'c' || c == 's' || c == 'S' || c == 'C')
		return (c);
	return (0);
}
