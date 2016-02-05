#include "../includes/ft_printf.h"

int		ft_isconv(int c)
{
	if (ft_isconvi(c) || ft_isconvc(c))
		return (c);
	return (0);
}
