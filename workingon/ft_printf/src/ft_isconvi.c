#include "../includes/ft_printf.h"

int		ft_isconvi(int c)
{
	if (c == 'd' || c == 'i')
		return ('d');
	if (c == 'u' || c == 'D' || c == 'U' || c == 'o' || c == 'O' ||\
		c == 'x' || c == 'X')
		return (c);
	return (0);
}
