#include "fillit_proto.h"

void		ft_place_tetri(char **map, t_sample *toplace, t_pos pos, int size)
{
	int		match;
	t_pos	carpos;

	match = 1;
	map[pos.y][pos.x] = toplace->c;
	while (match < 4)
	{
		carpos = ft_get_next_pos(pos, toplace->tetri, match);
		if (carpos.y < size && carpos.x < size)
			map[carpos.y][carpos.x] = toplace->c;
		match++;
	}
}
t_pos		ft_change_pos(char **map, t_pos pos, size_t size, t_sample *tmp)
{
	while (map[pos.y])
	{
		while (map[pos.y][++pos.x])
		{
			if (map[pos.y][pos.x] == '.')
				break ;
		}
		if (map[pos.y][pos.x] == '.')
			break ;
		pos.x = -1;
		pos.y++;
	}
	if (pos.y > size - 2 && pos.x > size - 2 && tmp->c == 'A')
	{
		pos.y = size;
		pos.x = size;
	}
	else if (pos.y > size - 2 && pos.x > size - 2)
	{
		pos = ft_pos_tetri(map);
		ft_remove_tetri(map, pos);
		if (pos.x > size)
		{
			pos.y++;
			pos.x = -1;
		}
		pos.x++;
	}
	return (pos);
}

t_pos		ft_pos_tetri(char **map)
{
	t_pos	pos;
	char	c;

	c = 0;
	pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
		{
			if (map[pos.y][pos.x] != '.' && map[pos.y][pos.x] > c)
				c = map[pos.y][pos.x];
		}
	}
	pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
		{
			if (map[pos.y][pos.x] == c)
				return (pos);
		}
	}
	return (pos);
}

void		ft_remove_tetri(char **map, t_pos pos)
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
					return ;
			}
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
}
