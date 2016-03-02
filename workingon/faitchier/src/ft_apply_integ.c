#include "../includes/ft_printf.h"

static int		apply_unsignedconv(char **cv, size_t arg, char c)
{
	if (c == 'o' || c == 'O')
		*cv = ft_sitoabase(arg, "01234567");
	else if (c == 'x')
		*cv = ft_sitoabase(arg, "0123456789abcdef");
	else if (c == 'X')
		*cv = ft_sitoabase(arg, "0123456789ABCDEF");
	else
		*cv = ft_sitoabase(arg, "0123456789");
	if (*cv == NULL)
		return (0);
	return (ft_strlen(*cv));
}

static ssize_t	get_arg(int lm, char c, va_list ap)
{
	ssize_t		arg;

	arg = 0;
	if (lm == 216 || c == 'D' || c == 'O' || c == 'U')
		arg = va_arg(ap, long long);
	else if (lm == 208)
		arg = (char)va_arg(ap , int);
	else if (lm == 108)
		arg = va_arg(ap, long);
	else if (lm == 104)
		arg = (short)va_arg(ap, int);
	else if (lm == 106)
		arg = va_arg(ap, intmax_t);
	else if (lm == 122)
		arg = va_arg(ap, ssize_t);
	else
		arg = va_arg(ap, int);
	return (arg);
}

int				ft_apply_integ(char **conv, char *info, va_list ap, int lm)
{
	ssize_t		arg;
	int			c;
	int			preci;

	preci = ft_getpreci(info);
	c = info[ft_strlen(info) - 1];
	arg = get_arg(lm, c, ap);
	if (arg == 0 && preci == 0)
	{
		if (!(*conv = ft_strdup("")))
			return (0);
		return (1);
	}
	if (c == 'o' || c == '0' || c == 'x' || c == 'u' || c == 'U')
		return (apply_unsignedconv(conv, arg, c));
	if (!(*conv = ft_sitoa(arg)))
		return (0);
	return (ft_strlen(*conv));
}
