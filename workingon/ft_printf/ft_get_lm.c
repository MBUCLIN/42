#include "ft_printf.h"

int		ft_get_lm(char *c)
{
	int		i;

	i = 0;
	while (c[i])
	{
		if (c[i] == 'l' && c[i + 1] == 'l' && ft_isconvi(c[i + 2]))
			return ('l' + 'l');
		else if (c[i] == 'h' && c[i + 1] == 'h' && ft_isconvi(c[i + 2]))
			return ('h' + 'h');
		else if ((c[i] == 'l' || c[i] == 'h' || c[i] == 'j' || c[i] == 'z') &&\
				(ft_isconvi(c[i + 1]))
				return (c[i]);
		i++;
	}
	return (0);
}
