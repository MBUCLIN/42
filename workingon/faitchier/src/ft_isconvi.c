#include "../includes/ft_printf.h"

int		ft_isconvi(int c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (2);
	else if (c == 'u' || c == 'U' || c == 'b' || c == 'o' || c == 'O' ||\
			c == 'x' || c == 'X')
		return (1);
	return (0);
}
