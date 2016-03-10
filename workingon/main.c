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
	n = ft_sitoabase((unsigned short)-151525, "0123456789abcdef");
	ft_putendl(n);
	free(n);
	n = NULL;
	return (0);
}
