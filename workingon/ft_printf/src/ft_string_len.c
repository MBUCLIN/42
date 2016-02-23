#include "../includes/ft_printf.h"

int		ft_string_len(char *s)
{
	int		i;

	i = 0;
	while (*(s + i) != 0)
		i++;
	return (i);
}
