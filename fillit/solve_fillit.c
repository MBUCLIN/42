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


t_pos		ft_get_dif(t_pos cur, t_pos next, t_pos pos)
{
	ft_putnbr(cur.y);
	ft_putchar(' ');
	ft_putnbr(cur.x);
	ft_putendl(" = cur");
	ft_putnbr(next.y);
	ft_putnbr(next.x);
	ft_putendl(" = next");
	pos.y = pos.y + ((cur.y - next.y) * -1);
	pos.x = pos.x + ((cur.x - next.x) * -1);
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
			if (map[pos.y][pos.x] != '.')
				c = map[pos.y][pos.x] + 1;
			pos.x++;
		}
		pos.y++;
	}
	if (c == '0')
		c = 'A';
	return (ft_search_tetri(tetri, c));
}

char		**ft_solve(t_sample *tetri, char **map, size_t size, t_pos pos)
{
	t_sample	*tmp;

	ft_putendl("New call");
	if (!(tmp = ft_get_tetri(tetri, map)))
		return (map);
	if (!(ft_check_pos(map, pos, tmp)))
	{
		ft_putendl("bad check pos");
		pos = ft_change_pos(map, pos, size, tmp);
		map = ft_solve(tetri, map, size, pos);
		if (pos.y == size && pos.x == size)
			return (map);
	}
	ft_putendl("placing tetri");
	ft_place_tetri(map, tmp, pos);
	pos = ft_change_pos(map, pos, size, tmp);
	ft_puttab(map);
	map = ft_solve(tetri, map, size, pos);
	if (pos.y == size && pos.x == size)
		return (map);
	return (map);
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
		map = ft_create_map(size);
		ft_solve(tetri, map, size, pos);
		size++;
	}
	return (map);
}
