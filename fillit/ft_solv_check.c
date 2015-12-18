#include "fillit.h"

t_pos ft_check_pos(char **map, t_pos pos, t_sample tetri)
{
	int	match;
	t_pos	new;

	match = 0;
	new.x = pos.x;
	new.y = pos.y;
	while (match != 4)
	{
		new = ft_get_next_pos(new, tetri, match);
		if (map[pos.y][pos.x] == '.')
			match++;
		else
			return (pos);
	}
	return (new);
}
