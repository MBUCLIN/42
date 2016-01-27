#include "ft_printf.c"

char	*ft_apply_int(int c, va_list ap)
{
	int	nbr;

	nbr = va_arg(ap, int);
	if (c == 'd' || c == 'i')
		return (ft_itoa(nbr));
	else if (c == o)
		return (ft_itoabase(nbr, "01234567"));
	else if (c == 'x')
		return (ft_itoabase(nbr, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_itoabase(nbr, "0123456789ABCDEF"));
	return (NULL);
}
