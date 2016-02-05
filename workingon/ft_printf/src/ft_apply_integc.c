#include "../includes/ft_printf.h"

static char		*apply_unsignedconv(size_t arg, int c)
{
	if (c == 'o' || c == 'O')
		return (ft_sitoabase(arg, "01234567"));
	else if (c == 'x')
		return (ft_sitoabase(arg, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_sitoabase(arg, "0123456789ABCDEF"));
	else
		return (ft_sitoabase(arg, "0123456789"));
	return (NULL);
}

char		*ft_apply_integc(int lm, int c, va_list ap)
{
	ssize_t		arg;

	if (lm == 216 || c == 'D' || c == 'O' || c == 'U')
		arg = va_arg(ap, long long);
	else if (lm == 208)
		arg = (char)va_arg(ap, int);
	else if (lm == 108)
		arg = va_arg(ap, long);
	else if (lm == 104)
		arg = (short)va_arg(ap, int);
	else if (lm == 106)
		arg = va_arg(ap, intmax_t);
	else if (lm == 122)
		arg = va_arg(ap, ssize_t);
	if (c == 'o' || c == 'O' || c == 'x' || c == 'X' || c == 'u' || c == 'U')
		return (apply_unsignedconv(arg, c));
	else
		return (ft_sitoa(arg));
	return (NULL);
}
