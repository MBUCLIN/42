#include "../includes/ft_printf.h"

void		ft_memset(void *p, int c, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		*(unsigned char *)(p + i) = c;
}
