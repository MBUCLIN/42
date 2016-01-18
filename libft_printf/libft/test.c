#include "libft.h"

int		main(int ac, char **av)
{
	int var;
	int *pvar;

	pvar = &var;
	ft_putnbrbase((long)pvar, "0123456789abcdef");
	return (0);
}
