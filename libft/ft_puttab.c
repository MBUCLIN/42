#include "libft.h"

void		ft_puttab(char **tab)
{
	int		i;

	i = 0;
	if (tab)
	while (tab[i])
	{
		if (!tab[i])
			return ;
		ft_putendl(tab[i]);
		i++;
	}
}
