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

static char		*apply_signedflags(char *info, char *conv)
{
	int		i;
	int		space;

	space = 0;
	i = 0;
	while (info[i])
	{
		if (info[i] == '+' && conv[0] != '-')
			return (ft_strdup("+"));
		else if (info[i] == ' ' && conv[0] != '-')
			space = 1;
		i++;
	}
	if (space == 1)
		return (ft_strdup(" "));
	return (NULL);
}

static char		*apply_flags(char *info, char *conv)
{
	int		c;

	c = info[ft_strlen(info) - 1];
	if (conv[0] != '0' && ft_isunsigned(c))
		return (apply_unsignedflags(c, info));
	return (apply_signedflags(info, conv));
}

int				ft_apply_flagsi(char **conv, char *info)
{
	int		adj;

	if (!(*conv = ft_strjoindfree(apply_flags(info, *conv), *conv)))
		return (0);
	adj = ft_getadj(info);
	if (!(*conv = ft_apply_pandw(adj, info, *conv)))
		return (0);
	return (ft_strlen(*conv));
}
