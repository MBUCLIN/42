#include "fillit.h"

int		ft_check_map(char **map, char max)
{
	t_xy	pos;
	char 	c;

	c = 'A';
	pos.y = -1
	while (map[++pos.y])
		{
			pos.x = -1;
			while (map[pos.y][++pos.x])
			{
				if (map[pos.y][pos.x] == c)
					c++;
			}
			if (c == c_max)
				return (0);
		}
		return (c);
}

int		ft_check_pos(char **map, t_xy pos)
{
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(map[i])
	if (size < pos.x || size < pos.y || pos.y < 0 || pos.x < 0)
		return (0);
	else if (map[pos.y][pos.x] != '.')
		return (0);
	return (1);
}

int		ft_check_tetri(char **add, char **map, t_xy pos)
{
	int		n;
	t_xy	tmp;

	tmp = pos;
	if (map[tmp.y][tmp.x] != '.')
		return (0);
	n = 1;
	while (n <= 4)
	{
		pos = ft_get_dif(add, n, tmp);
		if (ft_check_pos(map, tmp) == 0)
			return (0);
		n++;
	}
	return (1);
}
