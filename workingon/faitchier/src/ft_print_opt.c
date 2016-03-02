#include "../includes/ft_printf.h"

void	ft_printf_opt(char *opt, int size)
{
	write(1, opt, size);
}
