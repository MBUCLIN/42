#include "ft_printf_is.h"

int		is_flag(const char *fmt, int i)
{
	if (fmt[i] == '#' || fmt[i] == '0' || fmt[i] == '-' ||\
		fmt[i] == ' ' || fmt[i] == '+')
		return (fmt[i]);
	return (0);
}

int		is_width(const char *format, int i)
{
	char	*nbr;

	if (format[i] > '0' && format[i] <= '9')
		while (format[i])
		{
			if (format[i] >= '0' && format[i] <= '9')
			{
				if (!(nbr = ft_strjoinfree(nbr, &format[i])))
					return (-1);
			}
			else
				return (ft_atoi(nbr));
			i++;
		}
	return (0);
}

int		is_preci(const char *format, int i)
{
	char	*nbr;

	if (format[i] == '.')
		while (format[++i])
		{
			if (format[i] >= '0' && format[i] <= '9')
			{
				if (!(nbr = ft_strjoinfree(nbr, &format[i])))
					return (-1);
			}
			else
				return (ft_atoi(nbr));
		}
	return (0);
}

int		is_lm(const char *fmt, int i)
{
	if (fmt[i] == 'h')
	{
		if (fmt[i + 1] == 'h')
			return ('h' + 'h');
		else
			return ('h');
	}
	else if (fmt[i] == 'l')
	{
		if (fmt[i + 1] == 'l')
			return ('q');
		else
			return ('l');
	}
	else if (fmt[i] == 'L' || fmt[i] == 'j' || fmt[i] == 'z' || fmt[i] == 't')
		return (fmt[i]);
	return (0);
}

int		is_conv(const char *fmt, int i)
{
	if (fmt[i] == 's' || fmt[i] == 'S' || fmt[i] == 'p' || fmt[i] == 'd' ||\
		fmt[i] == 'D' || fmt[i] == 'i' || fmt[i] == 'o' || fmt[i] == 'O' ||\
		fmt[i] == 'u' || fmt[i] == 'U' || fmt[i] == 'x' || fmt[i] == 'X' ||\
		fmt[i] == 'c' || fmt[i] == 'C')
		return (fmt[i]);
	return (0);
}
