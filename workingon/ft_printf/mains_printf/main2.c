#include "../includes/ft_printf.h"
#include "locale.h"

int		main(void)
{
	int		c;
	unsigned int		n;
	char		*bin;

	c = 4;
	ft_printf("%-5.3c\n", 'c');
	ft_printf("%s\n", "salut");
	ft_printf("%-12.8s\n", NULL);
	ft_printf("%p\n", &c);
	ft_printf("%-20.15p\n", &c);
	ft_printf("%.5s\n", "abcdefghijklmnopqrstuvwxyz");

	if (!setlocale(LC_ALL, "en_US.UTF-8"))
		return (0);
	ft_printf("%lc\n", L'ù');
	ft_printf("%C\n", L'µ');
	ft_printf("%5lc\n", L'ù');
	ft_printf("%-5Ci\n", L'ۯ');
	ft_printf("%C%C%C%C\n", L'£', L'^', L'é', L'à');
	ft_putnbr(ft_printf("%.5ls\n", L"£$^ùµéà"));
	ft_putendl("");
	ft_putnbr(ft_printf("%.5s\n", "Hellow wordl"));
	ft_putendl("");
	ft_printf("%8ls\n", L"£µ¨ùµàç");
	ft_printf("%020d\n", -123456789);
	return (0);
}
