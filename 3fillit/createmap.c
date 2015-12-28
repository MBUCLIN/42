#include "fillit_proto.h"

t_pos		ft_get_next_pos(t_pos pos, char **tetri, int match)
{
	t_pos		next;
	int			count;
	int			size;

	next.y = -1;
	count = 0;
	while (tetri[++next.y])
	{
		next.x = -1;
		while (tetri[next.y][++next.x])
		{
			if (tetri[next.y][next.x] != '.' && count <= match)
			{
				count++;
			}
			if (count > match && tetri[next.y][next.x] != '.')
			{
				pos = ft_get_dif(next, pos, tetri);
				return (pos);
			}
		}
	}
	return (pos);
}

size_t		ft_get_pft_sqr(int n)
{
	int			mult;

	mult = 2;
	while (((mult * mult) - (n * 4)) < 0)
		mult++;
	return (mult);
}

char		**ft_push_tetri_left(char **tetri)
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
			if (tetri[y][0] != '.')
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
			tetri[y][4] = '\0';
		}
	}
	return (tetri);
}

void		ft_prepare_tetri(t_sample *tetri)
{
	t_sample	*temp;

	temp = tetri;
	while (temp)
	{
		temp->tetri = ft_push_tetri_left(temp->tetri);
		if (temp->tetri == NULL)
			return ;
		temp = temp->next;
	}
}

char		**ft_create_map(size_t size)
{
	char		**map;
	size_t		i;

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
