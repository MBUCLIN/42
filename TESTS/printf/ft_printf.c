#include "ft_printf.h"

static char		*get_output(const char *fmt, int max, va_list ap)
{
	int		i;
	int		n;
	int		start;
	char	*output;

	i = 0;
	start = i;
	n = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] != '%')
		{
			if (!(output = ft_strsub(fmt, start, i - 1)))
				return (NULL);
			if (!output = ft_conv(fmt, output, i, ap))
				return (NULL);
			i = after_conv(fmt, i);
			start = i;
		}
		i++;
	}
	return (output);
}

int		ft_printf(const char *format, ...)
{
	int			size;
	char		*output;
	int			n;
	va_list		ap;

	va_start(ap, format);
	if (!(output = get_output(format, n)))
		return (0);
	va_end(ap);
	size = ft_strlen(output);
	ft_putendl(output);
	free(output);
	return (size);
}
