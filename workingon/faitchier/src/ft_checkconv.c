#include "../includes/ft_printf.h"

int		ft_checkconv(const char *fmt, int i)
{
	while (fmt[++i])
		if (ft_isconv(fmt[i]))
			return (1);
	return (0);
}
