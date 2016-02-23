#include <stdio.h>
#include "../libft/includes/libft.h"
#include <locale.h>

int		main(void)
{
	if (!setlocale(LC_ALL, "en_US.UTF-8"))
		return (0);
	printf("%-5lci\n", L'ù');
	printf("%20ls\n", L"£ê");
	ft_putnbr(printf("%.5ls\n", L"£$^ùµéà"));
	ft_putendl("");
	ft_putnbr(printf("%.5s\n", "Hellow Wordl"));
	ft_putendl("");
	return (0);
}
