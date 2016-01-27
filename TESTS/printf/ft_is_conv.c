#include "ft_printf.c"

int		ft_is_conv(int c)
{
	int		ret;

	if ((ret = ft_is_int(c) || (ret = ft_is_long(c)) (ret == ft_is_char(c)) ||\
		(ret = ft_is_conv(c))))
		return (ret);
	return (0);
}
