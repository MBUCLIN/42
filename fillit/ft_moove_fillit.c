#include "../libft/libft.h"

t_pos		ft_pos_tetri(char **map)
{
	t_pos	pos;
	char	c;

	pos.y = 0;
	c = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] != '.' && map[pos.y][pos.x] > c)
				c = map[pos.y][pos.x];
			pos.x++;
		}
		pos.y++;
	}
	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == c)
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return (NULL);
}

char		**ft_remove_tetri(char **map, t_pos pos)
{
	char		c;
	int		count;

	c = map[pos.y][pos.x];
	count = 0;
	while (map[pos.y])
	{
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == c)
			{
				count++;
				map[pos.y][pos.x] = '.';
				if (count == 4)
					return (map);
			}
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
	return (NULL);
}

t_pos		ft_last_tetri(char **map, t_sample *tetri, t_pos pos)
{
	t_sample	*tmp;

	tmp = tetri;
	if (pos = ft_pos_tetri(map) == NULL)
		return (NULL);
	return (pos);
}
