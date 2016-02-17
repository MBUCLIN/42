#include "../includes/ft_printf.h"


static char		*apply_widthp(int adj, int width, int preci, char *adr)
{
	char		c;

	c = ' ';
	if (sizep == -1 && adj = 'l')
		c = '0';
}
static char		*get_p(int adj, char *adr, int sizew, int sizep)
{
	char	*preci;
	char	*width;
	int		len;

	preci = NULL;
	width = NULL;
	len = ft_strlen(adr);
	if (preci > len)
		if (!(preci = (char *)ft_memalloc(sizeof(char) * (sizep - len))))
			return (NULL);
	if (preci)
		ft_memset(preci, '0', sizep - len);
	if (!(adr = ft_strjoindfree(preci, adr)))
		return (NULL);
	if (sizew > (int)ft_strlen(adr))
	{
		sizew -= ft_strlen(adr);
		if (!(width = (char *)ft_memalloc(sizeof(char) * sizew)))
			return (NULL);
	}
	if (width)
		return (apply_widthp(adj, width, sizep, adr));
	if ()
	return (ft_strjoindfree(ft_strdup("Ox"), adr));
}

char			*ft_apply_convp(char *info, int adj, va_list ap)
{
	int		wi;
	int		pr;
	void	*p;

	p = va_arg(ap, void *);
	wi = ft_getwidth(info);
	pr = ft_getpreci(info);
	free(info);
	return (get_p(adj, ft_sitoabase((long)p, "0123456789abcdef"),wi , pr));
}
