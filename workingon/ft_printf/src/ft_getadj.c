#include "../includes/ft_printf.h"

int		ft_getadj(char *info)
{
	int		i;
	int		adj;

	i = 0;
	adj = 0;
	while (info[i])
	{
		if (info[i] == '-')
			return ('r');
		else if (info[i] == '0' && !ft_isdigit(info[i - 1]))
			adj = 'l';
		i++;
	}
	return (adj);
}
