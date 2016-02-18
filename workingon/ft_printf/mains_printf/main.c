#include <stdio.h>
#include "../libft/includes/libft.h"

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
	printf("%s = %p de i1\n", "adr", p1);
	printf("%s = %p de i2\n", "adr", p2);
	printf("%s = %p de i3\n", "adr", p3);
	printf("%.15p\n", p1);
	return (0);
}
