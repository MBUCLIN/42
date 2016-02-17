#include "../includes/ft_printf.h"

static char		*apply_mod(int adj, int sizew, int sizep)
{
	char	*preci;
	char	*width;

	preci = NULL;
	width = NULL;
	if (sizep > 1)
		if (!(preci = (char *)ft_memalloc(sizeof(char) * sizep - 1)))
			return (NULL);
	if (preci != NULL)
		ft_memset(preci, ' ', sizep - 1);
	if (!(preci = ft_strjoindfree(preci, ft_strdup("%"))))
		return (NULL);
	if (sizew > (int)ft_strlen(preci))
	{
		sizew -= ft_strlen(preci);
		if (!(width = (char *)ft_memalloc(sizeof(char) * sizew)))
			return (NULL);
	}
	if (width)
		ft_memset(width, ' ', sizew);
	if (adj == 'r')
		return (ft_strjoindfree(preci, width));
	return (ft_strjoindfree(width, preci));
}

static char		*apply_c(int adj, int sizew, int sizep, va_list ap)
{
	char	*width;
	char	*preci;
	char	c;

	width = NULL;
	preci = NULL;
	c = (char)va_arg(ap, int);
	if (sizep > 1)
		if (!(preci = (char *)ft_memalloc(sizeof(char) * (sizep - 1))))
			return (NULL);
	if (preci)
		ft_memset(preci, ' ', (sizep - 1));
	if (!(preci = ft_strjoindfree(preci, ft_strdup(&c))))
		return (NULL);
	if (sizew > (int)ft_strlen(preci))
	{
		sizew -= (int)ft_strlen(preci);
		if (!(width = (char *) ft_memalloc(sizeof(char) * sizew)))
			return (NULL);
	}
	if (width)
		ft_memset(width, ' ', sizew);
	if (adj == 'r')
		return (ft_strjoindfree(preci, width));
	return (ft_strjoindfree(width, preci));
}

char			*ft_apply_charc(char *info, int adj, va_list ap)
{
	int		width;
	int		preci;
	int		c;

	c = info[ft_strlen(info) - 1];
	width = ft_getwidth(info);
	preci = ft_getpreci(info);
	if (c == '%')
		return (apply_mod(adj, width, preci));
	else if (c == 'c')
		return (apply_c(adj, width, preci, ap));
	return (NULL);
}
