#include "fillit_proto.h"

int		ft_check_map(t_sample *tetri, char **map)
{
	t_pos	pos;
	char	c_max;

	pos.y = -1;
	c_max = ft_lstlen(tetri) + 64;
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

int		ft_check_pos(char **map, t_pos pos, t_sample *tetri, int size)
{
	int		match;
	t_pos	new;

	match = 1;
	new.x = pos.x;
	new.y = pos.y;
	ft_putendl("A");
	if (map[new.y][new.x] != '.')
		return (0);
	ft_putendl("B");
	while (match < 4)
	{
		ft_putchar('a');
		new = ft_get_next_pos(pos, tetri->tetri, match);
		ft_putchar('b');
		if (new.y < size && new.x < size && map[new.y][new.x] == '.')
		{
			ft_putchar('c');
			match++;
		}
		else
		{
			ft_putendl("D");
			return (0);
		}
	}
	ft_putendl("E");
	return (1);
}
