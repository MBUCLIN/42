#include <stdlib.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	char		*str;
	int			i;

	str = NULL;
	i = 0;
	while (str[i])
		i++;
	write(1, "salut", 5);
	return (0);
}
