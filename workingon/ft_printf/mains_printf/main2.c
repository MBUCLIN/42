#include "../includes/ft_printf.h"

int		main(void)
{
	int		c;

	c = 4;
	ft_printf("%-5.3c\n", 'c');
	ft_printf("%s\n", "salut");
	ft_printf("%-12.8s\n", NULL);
	ft_printf("%p\n", &c);
	ft_printf("%-20.15p\n", &c);
	return (0);
}
