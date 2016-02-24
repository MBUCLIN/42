#include <stdio.h>
#include "../libft/includes/libft.h"
#include <locale.h>

int		main(void)
{
<<<<<<< HEAD
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
=======
	if (!setlocale(LC_ALL, "en_US.UTF-8"))
		return (0);
	printf("%-5lci\n", L'ù');
	printf("%20ls\n", L"£ê");
	ft_putnbr(printf("%.5ls\n", L"£$^ùµéà"));
	ft_putendl("");
	ft_putnbr(printf("%.5s\n", "Hellow Wordl"));
	ft_putendl("");
>>>>>>> 14d33f3772610edfe4bffdc71747926a33151554
	return (0);
}
