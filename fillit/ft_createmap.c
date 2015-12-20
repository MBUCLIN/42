#include "fillit.h"

size_t	ft_get_pft_sqr(int n)
{
	int mult;

	mult = 2;
	while (((mult * mult) - (n * 4)) < 0)
		mult++;
	return (mult);
}

char	*ft_push_tetri_left(char **tetri, int size)
{
	char		*cpy;
	char		c;
	int			line;
	int			y;

	c = '.';
	line = -1;
	while (++line <= 2)
	{
		y = -1;
		while (tetri[++y])
			if (tetri != '.')
				return (tetri);
		y = -1;
		while (tetri[++y])
		{
			if (!(cpy = ft_strsub(tetri[y], 1, 4)))
				return (NULL);
			free(tetri[y]);
			tetri[y] = NULL;
			if (!(tetri[y] = ft_strjoin(cpy, &c)))
				return (NULL);
		}
	}
	return (tetri);
}

void	ft_prepare_tetri(t_sample *tetri)
{
	t_sample	*temp;
	int			size;

	temp = tetri;
	while (temp)
	{
		size = ft_strlen(temp->tetri);
		temp->tetri = ft_push_tetri_left(temp->tetri, size);
		if (temp->tetri == NULL)
			return ;
		temp = temp->next;
	}
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

