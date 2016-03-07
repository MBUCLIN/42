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

t_printf		*ft_apply_flagsi(char *info, t_printf *conv)
{
	int		adj;
	char	*flags;

	if (!(flags = apply_flags(info, conv->opt)))
		return (NULL);
	if (!(conv->opt = ft_strjoindfree(flags, conv->opt)))
		return (NULL);
	adj = ft_getadj(info);
	if (!(conv->opt = ft_apply_pandw(adj, info, conv->opt)))
		return (NULL);
	conv->size = ft_strlen(conv->opt);
	return (conv);
}
