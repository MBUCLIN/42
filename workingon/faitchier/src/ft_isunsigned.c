#include "../includes/ft_printf.h"

int		ft_isunsigned(int c)
{
	if (c == 'u' || c == 'U' || c == 'O' || c == 'o' ||\
		c == 'x' || c == 'X')
		return (1);
	return (0);
}
