/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_fillit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 17:09:18 by mbuclin           #+#    #+#             */
/*   Updated: 2015/12/18 17:45:04 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_proto.h"


t_pos		ft_get_dif(t_pos next, t_pos pos, char **tetri)
{
	int		x;

	x = 0;
	while (tetri[0][x] == '.')
		x++;
	pos.y = pos.y + next.y;
	pos.x = pos.x + (next.x - x);
	return (pos);
}

t_sample	*ft_search_tetri(t_sample *tetri, char c)
{
	t_sample	*tmp;

	tmp = tetri;
	while (tmp)
	{
		if (tmp->c == c)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

t_sample	*ft_get_tetri(t_sample *tetri, char **map)
{
	t_pos		pos;
	char		c;

	pos.y = 0;
	c = '0';
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] != '.' && map[pos.y][pos.x] >= c)
				c = map[pos.y][pos.x] + 1;
			pos.x++;
		}
		pos.y++;
	}
	if (c == '0')
		c = 'A';
	return (ft_search_tetri(tetri, c));
}

void		ft_solve(t_sample *tetri, char **map, size_t size, t_pos pos)
{
	t_sample	*tmp;
	int			boleen;

	tmp = tetri;
	boleen = 1;
	while (boleen == 1)
	{
		if (!(tmp = ft_get_tetri(tetri, map)))
			boleen = 0;
		if (!(ft_check_pos(map, pos, tmp, size)))
		{
			pos = ft_change_pos(map, pos, size, tmp);
			if (pos.y == size && pos.x == size && tmp->c == 'A')
				boleen = 0;
		}
		else
		{
			ft_place_tetri(map, tmp, pos);
			pos.y = 0;
			pos.x = 0;
		}
	}
	return ;
}

char		**ft_init_solv(t_sample *tetri)
{
	size_t		n;
	char		**map;
	size_t		size;
	t_pos		pos;

	pos.x = 0;
	pos.y = 0;
	map = NULL;
	n = ft_lstlen(tetri);
	ft_prepare_tetri(tetri);
	size = ft_get_pft_sqr((int)n);
	while (ft_check_map(tetri, map))
	{
		if (map)
			ft_tabdel((void **)map);
		if (!(map = ft_create_map(size)))
			return (NULL);
		ft_puttab(map);
		ft_putendl("");
		ft_solve(tetri, map, size, pos);
		size++;
	}
	return (map);
}
