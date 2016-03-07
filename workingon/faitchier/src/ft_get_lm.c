#include "../includes/ft_printf.h"

int			ft_get_lm(char *info)
{
	int		i;

	i = 0;
	while (info[i])
	{
		if (info[i] == 'l' && info[i + 1] == 'l')
			return ('l' + 'l');
		else if (info[i] == 'h' && info[i + 1] == 'h')
			return ('h' + 'h');
		else if (info[i] == 'l' || info[i] == 'h' || info[i] == 'j' ||\
				info[i] == 'z')
			return (info[i]);
		i++;
	}
	return (0);
}
