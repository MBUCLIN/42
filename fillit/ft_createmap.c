#include "fillit.h"

size_t	ft_get_pft_sqr(int n)
{
	int mult;

	mult = 2;
	while (((mult * mult) - (n * 4)) < 0)
		mult++;
	return (mult);
}

char **ft_create_map(size_t size)
{
	char **map;
	size_t i;

	i = 0;
	if (!(map = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(map[i] = (char *)ft_memalloc(sizeof(char) * (size + 1))))
			return (NULL);
		ft_memset(map[i], '.', size);
		map[i][size] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

char **ft_get_map_rdy(size_t n)
{
	size_t size;

	size = ft_get_pft_sqr((int)n);
	return (ft_create_map(size));
}
