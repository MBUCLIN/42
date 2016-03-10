#include "faitchier/includes/ft_printf.h"

int		main(void)
{
	ft_printf("%.2s is a string\n", "");
	ft_printf("%s\n", NULL);
	ft_printf("%s%s%s%s%s\n", "This", "is", "a", "multi", "string");
	ft_printf("%.2c\n", NULL);
	return (0);
}
