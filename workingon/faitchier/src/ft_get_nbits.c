#include "../includes/ft_printf.h"

int		ft_get_nbits(int wint)
{
	unsigned int	mask;
	int				n;

	n = 32;
	mask = 0x80000000;
	while (!(mask & wint))
	{
		n--;
		mask = mask >> 1;
	}
	return (n);
}
