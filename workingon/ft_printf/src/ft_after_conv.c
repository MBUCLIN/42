#include "../includes/ft_printf.h"

int		ft_after_conv(const char *fmt, int pos)
{
	if (fmt[pos + 1] == '%')
		return (pos + 1);
	while (fmt[pos])
	{
		if (ft_isconv(fmt[pos]))
			return (pos);
		pos++;
	}
	return (pos);
}
