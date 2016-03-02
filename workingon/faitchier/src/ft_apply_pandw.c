#include "../includes/ft_printf.h"

static char		*apply_preci(char *conv, int minus, int size, char *info)
{
	int		sizep;
	char	*preci;

	sizep = ft_getpreci(info);
	preci = NULL;
	if (size == 1 && sizep != -1 && conv[0] == '0')
		return (ft_strdup(""));
	sizep = sizep - (size - minus);
	if (!(preci = (char *)malloc(sizeof(char) * (sizep + 1))))
	{
		free(conv);
		return (NULL);
	}
	preci[sizep] = 0;
	if (preci)
		ft_memset(preci, '0', sizep);
	if (!(conv = ft_strmidadd(conv, preci, minus)))
		return (NULL);
	return (conv);
}

static char		*get_width(char *conv, char *width, int minus, int adj)
{
	if (adj == 'r')
		return (ft_strjoindfree(conv, width));
	else if (minus == 2 && width[0] == '0')
		return (ft_strmidadd(conv, width, 2));
	else if (minus == 1 && width[0] == '0')
		return (ft_strmidadd(conv, width, 1));
	return (ft_strjoindfree(width, conv));
}

static char		*apply_width(int adj, char *conv, char *info, int minus)
{
	char	*width;
	int		sizew;

	sizew = ft_getwidth(info) - ft_strlen(conv);
	if (sizew > 0)
		if (!(width = (char *)malloc(sizeof(char) * (sizew + 1))))
		{
			free(conv);
			return (NULL);
		}
	if (!width)
		return (conv);
	if (ft_getpreci(info) == -1 && adj == 'l')
		ft_memset(width, '0', sizew);
	else
		ft_memset(width, ' ', sizew);
	return (get_width(conv, width, minus, adj));
}

char			*ft_apply_pandw(int adj, char *info, char *conv)
{
	int		minus;
	int		size;

	size = ft_strlen(conv);
	minus = 0;
	if (conv && (conv[0] == '0' && (conv[1] == 'x' || conv[1] == 'X')))
		minus = 2;
	else if (conv && size > 1 && (conv[0] == '0' ||\
			 conv[0] == ' ' || conv[0] == '+' || conv[0] == '-'))
		minus = 1;
	if (!(conv = apply_preci(conv, minus, size, info)))
		return (NULL);
	size = ft_strlen(conv);
	return (apply_width(adj, conv, info, minus));
}
