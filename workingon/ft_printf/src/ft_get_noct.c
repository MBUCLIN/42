#include "../includes/ft_printf.h"

int			ft_get_noct(int n)
{
	if (n <= 7)
		return (1);
	else if (n <= 11)
		return (2);
	else if (n <= 16)
		return (3);
	return (4);
}
