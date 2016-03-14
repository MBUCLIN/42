#include "faitchier/includes/ft_printf.h"
#include <locale.h>
#include <stdio.h>

int		main(void)
{
//	ft_printf("%-5.10o\n", 2500);
//	ft_printf("%-10.5o\n", 2500);
//	ft_printf("%.10o\n", 42);
	ft_printf("%05d\n", -42);
	ft_printf("%0+5d\n", -42);
	ft_printf("%#.o, %#.0o\n", 0, 0);
	return (1);
}
