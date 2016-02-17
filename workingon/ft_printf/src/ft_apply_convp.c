#include "../includes/ft_printf.h"


static char		*apply_widthp(int adj, int sizew, int sizep, char *adr)
{
	char		c;
	char 		*width;

	c = ' ';
	width = NULL;
	if (sizew > (int)ft_strlen(adr))
	{
		sizew -= ft_strlen(adr);
		if (!(width = (char *)ft_memalloc(sizeof(char) * sizew)))
			return (NULL);
	}
	if (sizep == -1 && adj == 'l')
		c = '0';
	if (width)
		ft_memset(width, c, sizew);
	if (adj == 'r')
	{
		if (!(adr = ft_strjoindfree(adr, width)))
			return (NULL);
		return (adr);
	}
	return (ft_strjoindfree(width, adr));
}

static char		*get_p(int adj, char *adr, int sizew, int sizep)
{
	char	*preci;
	int		len;

	preci = NULL;
	if (!(adr = ft_strjoindfree(ft_strdup("0x"), adr)))
		return (NULL);
	len = ft_strlen(adr);
	if (sizep > len)
		if (!(preci = (char *)ft_memalloc(sizeof(char) * (sizep - len))))
			return (NULL);
	if (preci)
		ft_memset(preci, '0', sizep - len);
	if (!(adr = ft_strmidadd(adr, preci, 2)))
		return (NULL);
	if (sizew > (int)ft_strlen(adr))
		return (apply_widthp(adj, sizew, sizep, adr));
	return (adr);
}

char			*ft_apply_convp(char *info, int adj, va_list ap)
{
	int		wi;
	int		pr;
	long	adr;
	void	*p;

	p = va_arg(ap, void *);
	adr = (unsigned long)p;
	wi = ft_getwidth(info);
	pr = ft_getpreci(info);
	free(info);
	return (get_p(adj, ft_sitoabase(adr, "0123456789abcdef"),wi , pr));
}
