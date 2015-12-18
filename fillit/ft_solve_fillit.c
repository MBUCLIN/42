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

#include "fillit.h"


t_pos	ft_get_dif(t_pos cur, t_pos next, t_pos pos)
{
	pos.y = pos.y + ((cur.y - next.y) * -1);
	pos.x = pos.x + ((cur.x - next.x) * -1);
	return (pos);
}
t_pos	ft_get_next_pos(t_pos pos, t_sample *tetri, int match)
{
	t_pos next;
	t_pos cur;
	int	count;
	int	size;

	next.y = -1;
	count = 0;
	cur.x = 0;
	cur.y = 0;
	while (tetri[++next.y])
	{
		next.x = -1;
		while (tetri[next.y][++next.x])
		{
			if (tetri[next.y][next.x] != '.')
				count++;
			if (count == match && match != 0)
				cur = next;
			else if (count > match)
				return (ft_get_dif(cur, next, pos));
		}
	}
	return (NULL);
}

t_sample *ft_search_tetri(t_sample *tetri, char c)
{
	t_sample tmp;

	tmp = tetri;
	while (tmp)
	{
		if (tmp->c == c)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

t_sample *ft_get_tetri(t_sample *tetri, char **map)
{
	t_pos pos;
	char c;

	pos.y = 0;
	c = '0';
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x]!= '.')
				c = map[pos.y][pos.x];
			pos.x++;
		}
		pos.y++;
	}
	if (c == '0')
		c = 'A';
	return (ft_search_tetri(tetri, c));
}

char **ft_solve(t_sample *tetri, char **map, size_t size, t_pos pos)
{
	t_sample *tmp;

	tmp = ft_get_tetri(tetri, map);
	if (!(ft_check_pos(map, pos, tmp)))
	{
		pos = ft_last_tetri(map, tetri, pos);
		map = ft_remove_tetri(map, pos);
		pos = ft_change_pos(map, pos);
		if (ft_solve(tetri, map, size, pos) == NULL)
	}

}

char **ft_init_solv(t_sample *tetri)
{
	size_t n;
	char **map;
	size_t size;
	t_pos pos;

	pos.x = 0;
	pos.y = 0;
	n = ft_lstlen(tetri);
	size = ft_get_pft_sqr((int)n);
	while (ft_check_map(map, tetri))
	{
		if (map)
			ft_tabdel(map);
		map = ft_create_map(size);
		ft_solve(tetri, map, size, 'A', pos);
		size++;
	}
	return (map);
}
