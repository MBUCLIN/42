#include "../includes/ft_printf.h"

static int		get_convetwidth(char **conv, char *width, int adj, int len)
{
	int		n;

	n = 0;
	if (width[0] == '0')
		n = 2;
	else if (adj == 'r')
		n = len;
	if (!(*conv = ft_strmidadd(*conv, width, n)))
		return (0);
	return (ft_strlen(*conv));
}

static int		apply_widthp(int adj, char *info, char **conv, int len)
{
	char		*width;
	int			sizew;
	char		c;

	c = ' ';
	width = NULL;
	sizew = ft_getwidth(info) - ft_strlen(*conv);
	if (sizew > 0)
		if (!(width = (char *)malloc(sizeof(char) * sizew)))
			return (0);
	if (!width)
		return (len);
	width[sizew - 1] = '\0';
	if (ft_getpreci(info) == -1 && adj == 'l')
		c = '0';
	ft_memset(width, c, sizew - 1);
	return (get_convetwidth(conv, width, adj, len));
}

static int		get_p(int adj, char *info, char **conv, int len)
{
	char		*preci;
	int			sizep;

	sizep = ft_getpreci(info);
	if (!(*conv = ft_strjoindfree(ft_strdup("0x"), *conv)))
		return (0);
	if (sizep > len)
		if (!(preci = (char *)malloc(sizeof(char) * (sizep - len))))
			return (0);
	if (!preci)
		return (apply_widthp(adj, info, conv, len + 2));
	preci[sizep - len] = '\0';
	ft_memset(preci, '0', sizep - len);
	if (!(*conv = ft_strmidadd(*conv, preci, 2)))
		return (0);
	return (apply_widthp(adj, info, conv, len + (sizep - len) + 2));
}

int				ft_apply_convp(char *info, int adj, char **conv, va_list ap)
{
	long 		adr;
	void		*p;

	p = va_arg(ap, void *);
	adr = (unsigned long)p;
	if (!(*conv = ft_sitoabase(adr, "0123456789abcdef")))
		return (0);
	return (get_p(adj, info, conv, ft_strlen(*conv)));
}
