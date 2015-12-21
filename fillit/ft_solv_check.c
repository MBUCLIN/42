#include "fillit.h"

int		ft_check_map(t_sample *tetri, char **map)
{
	t_pos	pos;
	char	c_max;

	pos.y = -1;
	c_max = ft_lstlen(tetri) + 'A';
	if (!map)
		return (1);
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
		{
			if (map[pos.y][pos.x] == c_max)
				return (0);
		}
	}
	return (1);
}

int		ft_check_pos(char **map, t_pos pos, t_sample tetri)
{
	int		match;
	t_pos	new;
	int		size;

	match = 0;
	size = 0;
	new.x = pos.x;
	new.y = pos.y;
	while (match != 4)
	{
		new = ft_get_next_pos(new, tetri, match);
		if (map[new.y][new.x] == '.')
			match++;
		else
			return (0);
	}
	return (1);
}
