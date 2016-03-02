#include "../includes/ft_printf.h"

int		ft_getlen(const char *fmt)
{
	int		i;

	i = 0;
	while (fmt[i])
		if (fmt[i] == '%' && ft_checkconv(fmt, i))
			return (i);
	return (i);
}
