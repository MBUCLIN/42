#include "../includes/ft_printf.h"

static char		*apply_mod(int adj, int sizew, int sizep)
{
	char	*width;
	char	*preci;

	if (sizep != -1)
	{
		if (!(preci = (char *)ft_memalloc(sizeof(char) * sizep)))
			return (NULL);
		sizew = sizew - (sizep - 2);
	}
	if (preci)
		ft_memset(preci, ' ', sizep - 2);
	if (!(preci = ft_strjoindfree(preci, ft_strdup("%"))))
		return (NULL);
	if (sizew)
		if (!(width = (char *)ft_memalloc(sizeof(char) * sizew)))
			return (NULL);
	if (width)
		ft_memset(width, ' ', sizew - 2);
	if (adj == 'r')
		return (ft_strjoindfree(preci, width));
	else
		return (ft_strjoindfree(width, preci));
	return (NULL);
}

static char		*apply_c(int adj, int sizew, int sizep, va_list ap)
{
	char		*width;
	char		c;
	char		*preci;

	c = va_arg(ap, char);
	if (sizep != -1)
	{
		if (!(preci = (char *)ft_memalloc(sizeof(char) * sizep)))
			return (NULL);
		sizew = sizew - (sizep - 2);
	}
	if (preci)
		ft_memset(preci, ' ', sizep - 2);
	if (!(preci = ft_strjoindfree(preci, ft_strdup("%"))))
		return (NULL);
	if (sizew)
		if (!(width = (char *)ft_memalloc(sizeof(char) * sizew)))
			return (NULL);
	if (width)
		ft_memset(width, ' ', sizew - 2);
	if (adj == 'r')
		return (ft_strjoindfree(preci, width));
	else
		return (ft_strjoindfree(width, preci));
	return (NULL);
}

static char		*apply_convc(char *info, int lm, int adj, va_list ap)
{
	int		width;
	int		preci;
	int		c;

	c = ft_strlen(info) - 1;
	width = ft_getwidth(info);
	preci = ft_getpreci(info);
	if (c == '%')
		return (apply_mod(adj, width, preci))
	else if (c == 'c')
		return (apply_c(adj, width, preci, ap));
	return (NULL);
}

char			*ft_apply_conv(char *info, va_list ap, int lm)
{
	int		c;
	int		adj;

	adj = ft_getadj(info);
	c = info[ft_strlen(info) - 1];
	if (ft_isconvc(c) || c == '%')
		return (apply_convc(info, lm, adj, ap));
	else if (ft_isconvs(c))
		return (apply_convs(info, lm, adj, ap));
	return (NULL);
}
