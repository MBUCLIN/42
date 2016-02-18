#include "../includes/ft_printf.h"

int		main(void)
{
	void *p1;
	void *p2;
	void *p3;
	int	i1;
	int	i2;
	int	i3;

	p1 = &i1;
	p2 = &i2;
	p3 = &i3;
	ft_printf("%s = %p de i1\n", "adr", p1);
	ft_printf("%s = %p de i2\n", "adr", p2);
	ft_printf("%s = %p de i3\n", "adr", p3);
	ft_printf("%15p\n", p1);
	return (0);
}
