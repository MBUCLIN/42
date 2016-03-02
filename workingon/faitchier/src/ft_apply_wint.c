#include "../includes/ft_printf.h"

int		ft_apply_wint(char *info, int adj, char **conv, va_list ap)
{
	int		wint;
	int		n;
	char	*oct;

	oct = NULL;
	wint = va_arg(ap, int);
	n = ft_get_nbits(wint);
	if (!(oct = ft_getoct(wint, ft_getmask(n))))
		return (0);
	n = ft_get_noct(n);
	if (!(*conv = ft_convoct(oct, n)))
		return (0);
	return (ft_apply_widtchar(info, conv, adj, n));
}
