/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkvalidity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 12:05:52 by lgosse            #+#    #+#             */
/*   Updated: 2015/12/17 14:15:30 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_proto.h"

int		ft_check_empty_lines(char *read_result)
{
	int i;

	i = 0;
	while (read_result[i] != '\0')
	{
		i += 20;
		if (read_result[i] != '\n' && read_result[i] != '\0')
		{
			ft_putendl("error");
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_check_tetri(char **sample, t_pos pos)
{
	int		nb;

	nb = 0;
	if (sample[pos.y][pos.x + 1] == '#')
	{
		pos.x++;
		nb += ft_check_tetri(sample, pos) + 1;
		pos.x--;
	}
	if (sample[pos.y + 1][pos.x] == '#')
	{
		pos.y++;
		nb += ft_check_tetri(sample, pos) + 1;
		pos.y--;
	}
	if (sample[pos.y][pos.x - 1] == '#')
	{
		pos.x--;
		nb += ft_check_tetri(sample, pos) + 1;
	}
	return (nb);
}

t_pos	ft_get_first_pos(char **sample, int y)
{
	t_pos	pos;
	int		x;

	while (sample[y][x] != '#')
	{
		while (x < 4)
		{
			if (sample[y][x] != '#')
				x++;
		}
		y++;
	}
	pos.x = x;
	pos.y = y;
	return (pos);
}

int		ft_check_block(char **sample, int y)
{
	int x;
	int i;
	int nb_f;

	i = 0;
	nb_f = 0;
	while (i < 4)
	{
		x = 0;
		while (x < 4 && &sample[y + i][x] != NULL)
		{
			if (sample[y + i][x] != '.' && sample[y + i][x] != '#')
				return (0);
			if (sample[y + i][x] == '#')
				nb_f++;
			x++;
		}
		if (sample[y + i][x] != '\0' || x != 4)
			return (0);
		i++;
	}
	if (nb_f != 4 && ft_check_tetri(sample, ft_get_first_pos(sample, y)))
		return (0);
	return (1);
}

int		ft_is_sample_valid(char **sample)
{
	int y;

	y = 0;
	while (sample[y] != NULL)
	{
		if (ft_check_block(sample, y) != 1)
			return (0);
		y += 4;
	}
	if (y == 0)
		return (0);
	return (1);
}
