#include "../includes/ft_printf.h"

int		ft_getpreci(char *info)
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
