#include "ft_printf_h"

int		ft_is_long(int c)
{
	if (c == 'D' || c == 'U' || c == 'O')
		return (c);
	return (0);
}
