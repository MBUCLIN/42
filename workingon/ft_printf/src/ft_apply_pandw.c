#include "../includes/ft_printf.h"

static int		get_preci(char *info)
{
	int		i;

	i = 0;
	while (info[i])
	{
		if (info[i] == '.')
		{
			i++;
			return (ft_atoi((info + i)));
		}
		i++;
	}
	return (-1);
}

static int		get_width(char *info)
{
	int		i;

	i = 0;
	while (info[i])
	{
		if (info[i] >= '0' && info[i] <= '9' && info[i - 1] != '.')
		{
			return (ft_atoi((info + i)));
		}
	i++;
	}
	return (-1);
}

static char		*apply_width(int adj, int width, int preci, char *conv)
{
	char	*add;

	if (!(add = (char *)ft_memalloc(sizeof(char) * (width + 1))))
		return (NULL);
	if (preci == -1 && adj == 'l')
		ft_memset(add, '0', width - 1);
	else
		ft_memset(add, ' ', width - 1);
	if (adj == 'r')
		return (ft_strjoindfree(conv, add));
	return (ft_strjoindfree(add, conv));
}

static char		*apply_preci(int preci, char *conv)
{
	int		i;
	char	*add;

	i = -1;
	if (!(add = (char *)ft_memalloc(sizeof(char) * (preci + 1))))
		return (NULL);
	while (++i < preci)
		add[i] = '0';
	if (conv[0] == '0')
		add = ft_strmidadd(ft_strdup(conv), add, 2);
	else if (conv[0] == ' ' || conv[0] == '+')
		add = ft_strmidadd(ft_strdup(conv), add, 1);
	else
		add = ft_strjoindfree(ft_strdup(conv), add);
	if (add == NULL)
	{
		free(conv);
		return (NULL);
	}
	free(conv);
	return (NULL);
}

char			*ft_apply_pandw(int adj, char *info, char *conv)
{
	int		width;
	int		preci;

	width = get_width(info);
	preci = get_preci(info);
	if (preci > (int)ft_strlen(conv))
	{
		preci = preci - ft_strlen(conv);
		if (!(conv = apply_preci(preci, conv)))
			return (NULL);
	}
	else
	if (width > (int)ft_strlen(conv) && width > preci)
		if (!(conv = apply_width(adj, width - ft_strlen(conv), preci, conv)))
			return (NULL);
	return (conv);
}
