/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkvalidity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 12:05:52 by lgosse            #+#    #+#             */
/*   Updated: 2015/12/28 18:09:26 by mbuclin          ###   ########.fr       */
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
			ft_putchar(read_result[i]);
			ft_putendl("error1");
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_get_x_size(char **sample, int y)
{
	int		x;
	int		i;
	int		start;
	int		end;

	start = 0;
	end = 0;
	x = -1;
	i = 0;
	while (++x < 4 && sample[y + i][x] != '#')
	{
			i = 0;
			while (sample[y + i][x] != '#' && i < 4)
				i++;
			start = x;
	}
	x = 4;
	while (--x >= 0 && sample[y + i][x] != '#')
	{
		i = 3;
		while (sample[y + i][x] && i >= 0)
			i--;
		end = x;
	}
	return (end - start);
}

int		ft_check_tetri(char **sample, int y)
{
	int 	x;
	int		i;
	int		start;
	int		end;
	int		n;

	start = 0;
	end = 0;
	i = -1;
	x = 0;
	ft_putchar('a');
	while(++i < 4 && sample[y + i][x] != '#' && sample[y + i])
	{
		x = 0;
		while (sample[y + i][x] != '#' && x < 4 && sample[y + i][x])
			x++;
		start = y + i;
	}
	ft_putchar('b');
	i = 4;
	while (--i >= 0 && sample[y + i][x] != '#')
	{
		x = 3;
		while (sample[y + i][x] != '#' && x >= 0)
			x--;
		end = y + i;
	}
	ft_putchar('c');
	n = (end - start) + ft_get_x_size(sample, y);
	ft_putnbr(n);
	return(n);
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
	if (nb_f != 4 || ft_check_tetri(sample, y) >= 6)
		return (0);
	return (1);
}

int		ft_is_sample_valid(char **sample)
{
	int y;

	y = 0;
	ft_putendl("A");
	while (sample[y] != NULL)
	{
		ft_putendl("B");
		if (ft_check_block(sample, y) != 1)
			return (0);
		ft_putendl("C");
		y += 4;
	}
	if (y == 0)
		return (0);
	return (1);
}
