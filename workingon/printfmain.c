#include <stdio.h>
#include "faitchier/includes/ft_printf.h"

int		main(void)
{
	char *n;

	n = ft_sitoa(printf("Ceci est %cun caractere\n", '\0'));
	write(1, n, ft_strlen(n));
	free(n);
	printf("%d\n", 0);
	printf("%i\n", 0);
	printf("%03.2d", 0);
	return (0);
}
