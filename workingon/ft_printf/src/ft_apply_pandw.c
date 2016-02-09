#include "../includes/ft_printf.h"

static int		get_width(char *info)
{
	int		i;

	i = 0;
	while (info[i])
	{
		if ((info[i] > '0' && info[i] <= '9') && info[i - 1] == '.')
			while (info[i] >= '0' && info[i] <= '9')
				i++;
		if ((info[i] > '0' && info[i] <= '9') && info[i - 1] != '.')
			return (ft_atoi((info + i)));
		i++;
	}
	return (-1);
}

static int		get_preci(char *info)
{
	int		i;

	i = 0;
	while (info[i])
	{
		if (info[i] == '.')
			return (ft_atoi((info + i + 1)));
		i++;
	}
	return (-1);
}

static char		*apply_preci(int preci, char *conv, int cut)
{
	char		*add;

	add = NULL;
	if (!(add = (char *)ft_memalloc(sizeof(char) * (preci + 1))))
	{
		free(conv);
		return (NULL);
	}
	ft_memset(add, '0', preci);
	if (!(add = ft_strmidadd(conv, add, cut)))
		return (NULL);
	return (add);
}

static char		*apply_width(int adj, int width, int preci, char *conv)
{
	char		*add;

	add = NULL;
	if (!(add = (char *)ft_memalloc(sizeof(char) * (width - preci + 1))))
	{
		free(conv);
		return (NULL);
	}
	if (preci == -1 && adj == 'l')
		ft_memset(add, '0', width);
	else
		ft_memset(add, ' ', width);
	if (adj == 'r')
		return (ft_strjoindfree(conv, add));
	else if (((conv[1] == 'x' || conv[1] == 'X') && conv[0] == '0') &&\
			add[0] == '0')
		return (ft_strmidadd(conv, add, 2));
	else if (add[0] == '0' && (conv[0] == ' ' ||\
			conv[0] == '+' || conv[0] == '0'))
		return (ft_strmidadd(conv, add, 1));
	return (ft_strjoindfree(add, conv));
}

char			*ft_apply_pandw(int adj, char *info, char *conv)
{
	int			width;
	int			preci;
	int			minus;
	int			size;

	size = ft_strlen(conv);
	minus = 0;
	width = get_width(info);
	preci = get_preci(info);
	free(info);
		if (conv[0] == '0' && (conv[1] == 'x' || conv[1] == 'X') &&\
			size != 1)
			minus = 2;
		else if ((conv[0] == '0' || conv[0] == ' ' || conv[0] == '+') &&\
				size != 1)
			minus = 1;
	if (preci > size - minus)
	{
		preci = preci - (size - minus);
		if (!(conv = apply_preci(preci, conv, minus)))
			return (NULL);
		size = ft_strlen(conv);
	}
	if (minus)
		minus = 1;
	if (width > size)
		if (!(conv = apply_width(adj, width - size, preci, conv)))
			return (NULL);
	return (conv);
}