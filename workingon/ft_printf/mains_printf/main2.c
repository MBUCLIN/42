#include "../includes/ft_printf.h"

int		main(void)
{
	ft_printf("%#10.5o\n", 42);
	ft_printf("%.5i\n", 250);
	ft_printf("%5%\n");
	return (0);
}
