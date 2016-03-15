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
	if (!setlocale(LC_ALL, "en_US.UTF-8"))
		return (0);
	ft_printf("%C\n", 855);
	ft_printf("%C\n", 4500);
	ft_printf("%C\n", 150000);
	ft_printf("%.*s\n", 5, 0);
	ft_printf("%S\n", NULL);
	ft_printf("%C\n", NULL);
	return (1);
}
