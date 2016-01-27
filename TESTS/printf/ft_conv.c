#include "ft_printf.h"

int		get_nconv(const char *fmt)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (fmt)
		while (fmt[i])
		{
			if (fmt[i] == '%' && fmt[i + 1] != '%')
				n++;
		}
	return (n);
}

int		ft_conv(const char *fmt, char *opt, int i, va_list ap)
{
	char	*conv;
	int		c;

	while (fmt[i])
	{
		if ((c = ft_is_conv(fmt[i])))
			conv = ft_apply_conv(c, ap)
	}
}
