#include "libft/includes/libft.h"

void		ft_print_bit(unsigned char octet)
{
	unsigned char	mask;
	int				h;

	h = 8;
	mask = 0b10000000;
	while (h)
	{
		if (octet & mask)
			ft_putchar('1');
		else
			ft_putchar('0');
		mask = mask >> 1;
		h--;
	}
}
