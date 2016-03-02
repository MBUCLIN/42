#include "../includes/ft_printf.h"

int		ft_isconv(int c)
{
	if (ft_isconvc(c) || ft_isconvi(c))
		return (1);
	return (0);
}
