#include "../includes/ft_printf.h"

int		main(void)
{
	ft_printf("%+.5d\n", 0);
	ft_printf("%+.5i\n", 0);
	ft_printf("%+.5u\n", 0);
	ft_printf("%+.5o\n", 0);
	ft_printf("%+.5x\n", 0);
	ft_printf("%+.5X\n", 0);
	return (0);
}
