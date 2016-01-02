#include "libft.h"

void		ft_tabdel(void **todel)
{
	size_t		i;

	i = 0;
	if (todel)
	while ((unsigned char *)todel[i])
	{
		free(todel[i]);
		todel[i] = NULL;
	}
	free(todel);
	todel = NULL;
}
