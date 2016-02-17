#include "../includes/ft_printf.h"

int		main(void)
{
	ft_printf("%-5.3c\n", 'c');
	ft_printf("%s\n", "salut");
	ft_printf("%-12.8s\n", NULL);
	return (0);
}
