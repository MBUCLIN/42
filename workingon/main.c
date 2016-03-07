#include "ft_printf/includes/ft_printf.h"

int		main(void)
{
	char	*n;

	n = ft_sitoa(ft_printf("Ceci est %cun caractere\n", '\0'));
	write(1, n, ft_strlen(n));
	ft_putendl("");
	ft_printf("%d\n", 0);
	ft_printf("%i\n", 0);
	free(n);
	return (0);
}
