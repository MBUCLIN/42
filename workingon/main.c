#include "ft_printf/includes/ft_printf.h"

int		main(void)
{
	char	*n;

	n = ft_sitoa(ft_printf("Ceci est %cun caractere\n", '\0'));
	write(1, n, ft_strlen(n));
	ft_putendl("");
	free(n);
	n = NULL;
	n = ft_sitoa(ft_printf("%d\n", 0));
	ft_putendl(n);
	free(n);
	n = NULL;
	ft_printf("%i\n", 0);
	n = ft_sitoa(ft_printf("%d\n", 75000));
	write(1, n, ft_strlen(n));
	ft_putendl("");
	free(n);
	n = NULL;
	n = ft_sitoa(ft_printf("%X\n", 75000));
	write(1, n, ft_strlen(n));
	ft_putendl("");
	free(n);
	n = NULL;
	n = ft_sitoa(ft_printf("%D\n", -75000));
	ft_putendl(n);
	free(n);
	n = NULL;
	n = ft_sitoa(ft_printf("%o\n", -75000));
	ft_putendl(n);
	free(n);
	n = NULL;
	ft_printf("%d%d%d%d%d\n", 1, -2, 3, -4, 5);
	ft_printf("%d", 42);
	ft_printf("@moulitest: %5.x, %5.0x\n", 0, 0);
	ft_printf("%5%\n");
	ft_printf("%%\n");
	ft_printf("%10x\n", 42);
	ft_printf("%010x\n", 542);
	ft_printf("@moulitest: %#.x, %#.0x\n", 0, 0);
	ft_printf("%.2s is a string\n", "this");
	ft_printf("%5p\n", &n);
	sleep(15);
	return (0);
}
