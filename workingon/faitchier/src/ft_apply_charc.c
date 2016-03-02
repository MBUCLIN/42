#include "../includes/ft_printf.h"

static int		apply_c(int adj, char **conv, char *info, va_list ap)
{
	int		sizep;
	char	*preci;
	char	c;

	preci = NULL;
	sizep = ft_getpreci(info);
	if (info[ft_strlen(info) - 1] != '%')
		c = (char)va_arg(ap, int);
	else
		c = '%';
	if (sizep > 1)
		if (!(preci = (char *)malloc(sizeof(char) * (sizep - 1))))
			return (0);
	if (sizep < 1)
		return (ft_apply_widtchar(info, conv, adj, 1));
	ft_memset(preci, ' ', (sizep - 1));
	if (!(*conv = ft_strjoindfree(preci, ft_strdup(&c))))
		return (0);
	return (ft_apply_widtchar(info, conv, adj, sizep));
}

int				ft_apply_charc(char *info, int adj, char **conv, va_list ap)
{
	return (apply_c(adj, conv, info, ap));
}
