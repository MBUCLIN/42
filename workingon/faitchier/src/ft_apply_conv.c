#include "../includes/ft_printf.h"

static char		*cpy_conv(char *arg, int len)
{
	int		i;
	char	*cpy;

	if (!(cpy = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		cpy[i] = *(arg + i);
	cpy[i] = '\0';
	return (cpy);
}

static int		get_convs(int len, int adj, char **conv, char *info)
{
	char	*preci;
	int		sizep;

	sizep = ft_getpreci(info);
	preci = NULL;
	if (sizep > len && len > 0)
	{
		if (!(preci = (char *)malloc(sizeof(char) * (sizep - len))))
			return (0);
		preci[sizep - len] = '\0';
	}
	else if (sizep == -1)
		return (ft_apply_widtchar(info, conv, adj, len));
	if (preci == NULL)
		return (0);
	ft_memset(preci, ' ', sizep - len);
	if (!(*conv = ft_strjoindfree(preci, *conv)))
		return (0);
	return (ft_apply_widtchar(info, conv, adj, len));
}

static int		apply_convs(char *info, int adj, char **conv, va_list ap)
{
	int		len;
	char	*s;

	s = NULL;
	s = va_arg(ap, char *);
	if (s == NULL)
	{
		*conv = ft_strdup("(null)");
		return (get_convs(6, adj, conv, info));
	}
	len = ft_string_len(s);
	if (!(*conv = cpy_conv(s, len)))
		return (0);
	return (get_convs(len, adj, conv, info));
}

int				ft_apply_conv(char **conv, char *info, int lm, va_list ap)
{
	int		c;
	int		adj;

	adj = ft_getadj(info);
	c = info[ft_strlen(info) - 1];
	if ((c == 'c' && lm != 'l') && c == '%')
		return (ft_apply_charc(info, adj, conv, ap));
	else if (c == 's' && lm != 'l')
		return (apply_convs(info, adj, conv, ap));
	else if (c == 'P' || c == 'P')
		return (ft_apply_convp(info, adj, conv, ap));
	else if (c == 'C' || c == 'c')
		return (ft_apply_wint(info, adj, conv, ap));
	return (ft_apply_wchar(info, adj, conv, ap));
}
