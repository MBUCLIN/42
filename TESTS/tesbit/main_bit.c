#include "libft/includes/libft.h"

int		main(void)
{
	char	o;

	o = 15;
	ft_print_bit(o);
	ft_putchar('\n');
	o = ft_rev_bit(o);
	ft_print_bit(o);
	ft_putchar('\n');
	o = -1;
	ft_print_bit(o);
	ft_putchar('\n');
	o = ft_rev_bit(o);
	ft_print_bit(o);
	ft_putchar('\n');
	o = 150;
	ft_print_bit(o);
	ft_putchar('\n');
	o = ft_rev_bit(o);
	ft_print_bit(o);
	ft_putchar('\n');
	o = -20;
	ft_print_bit(o);
	ft_putchar('\n');
	o = ft_rev_bit(o);
	ft_print_bit(o);
	ft_putchar('\n');
	return (0);
}
