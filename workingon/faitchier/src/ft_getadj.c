#include "../includes/ft_printf.h"

int		ft_getadj(char *info)
{
	int		i;
	int		adj;

	adj = 0;
	i = 0;
	while (info[i])
	{
		if (info[i] == '-')
			return ('r');
		else if (info[i] == '0' &&\
				(!ft_isdigit(info[i - 1]) || info[i - 1] != '.'))
			adj = 'l';
	}
	return (adj);
}
