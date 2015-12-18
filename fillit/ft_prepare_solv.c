#include "fillit.h"

size_t	ft_sample_len(t_samp *tetri)
{
	t_samp	*tmp;
	size_t		n;

	tmp = tetri;
	while (tmp)
	{
		n++;
		tmp = tmp->next;
	}
	return (n);
}

char	**ft_create_map(size_t n)
{
	int		i;
	char		**map;

	tmp = tetri;
	i = 0;
	 if (!(map = (char **)ft_memalloc(sizeof(char) * (n + 1))))
		 return (NULL);
	while (i < n)
	{
		if (!(map[i] = (char *)ft_memalloc(sizeof(char) * (n + 1))))
			return (NULL);
		ft_memset(map[i], '.', n);
		i++;
	}
	map[i] = NULL;
	return (map);
}

size_t	ft_get_perfect_square(size_t n)
{
	size_t mult;

	mult == 2;
	while ((int)((mult * mult) - (n * 4i)) < 0)
		mult++;
	return (mult);
}

char	**ft_get_map_rdy(t_samp *tetri, size_t n)
{
	char	c_max;

	if (n == 0)
	{
		n = ft_sample_len(tetri);
		c_max = n + 'A';
		n = ft_get_perfect_square(n);
	}
	return (ft_create_map(n));
}
