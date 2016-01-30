#include "../includes/ft_printf.h"

int		ft_get_flag(char *inf)
{
	int		c;
	int		i;

	i = 0;
	while (inf[i])
	{
		c = inf[i];
		if (c == '#')
			return (c);
		i++;
	}
	return (0);
}
