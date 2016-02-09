#include "../includes/ft_printf.h"

static char		*apply_unsignedflags(int c, char *info)
{
	int		i;

	i = 0;
	while (info[i])
	{
		if (info[i] == '#')
		{
			if (c == 'x')
				return (ft_strdup("0x"));
			else if (c == 'X')
				return (ft_strdup("0X"));
			else
				return (ft_strdup("0"));
		}
		i++;
	}
	return (NULL);
}

static char		*apply_signedflags(char *info)
{
	int		i;
	int		space;

	space = 0;
	i = 0;
	while (info[i])
	{
		if (info[i] == '+')
			return (ft_strdup("+"));
		else if (info[i] == ' ')
			space = 1;
		i++;
	}
	if (space == 1)
		return (ft_strdup(" "));
	return (NULL);
}

static char		*apply_flags(int c, char *info, char *conv)
{
	if (conv[0] != '0' && (c == 'x' || c == 'X' || c == 'o' || c == 'O'))
		return (apply_unsignedflags(c, info));
	else if (c == 'd' || c == 'i')
		return (apply_signedflags(info));
	return (NULL);
}

static int		get_adj(char *info)
{
	int		i;
	int		adj;

	i = 0;
	adj = 0;
	while (info[i])
	{
		if (info[i] == '-')
			return ('r');
		else if (info[i] == '0')
			adj = 'l';
		i++;
	}
	return (adj);
}
char			*ft_apply_flagsi(char *info, char *conv)
{
	int		c;
	int		adjustment;

	c = info[ft_strlen(info) - 1];
		if (!(conv = ft_strjoindfree(apply_flags(c, info, conv), conv)))
			return (NULL);
	adjustment = get_adj(info);
	if (!(conv = ft_apply_pandw(adjustment, info, conv)))
		return (NULL);
	return (conv);
}