#include "ft_printf.h"

int		ft_iswconv(int c)
{
	if (c == 'C' || c == 'S')
		return (c);
	return (0);
}
