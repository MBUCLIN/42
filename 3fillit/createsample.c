/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createsample.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgosse <lgosse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 16:58:13 by lgosse            #+#    #+#             */
/*   Updated: 2015/12/28 14:09:07 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_proto.h"

t_sample	*ft_newtetri(char **tetri, int y)
{
	t_sample	*new_sample;

	new_sample = (t_sample *)malloc(sizeof(t_sample));
	if (new_sample != NULL)
	{
		new_sample->tetri = tetri;
		new_sample->next = NULL;
		new_sample->c = y / 4 + 'A';
		ft_change_lst_char(new_sample);
	}
	return (new_sample);
}

char		**ft_emptygrid(void)
{
	char	**tetri;
	int		y;
	int		x;

	y = -1;
	x = -1;
	tetri = (char **)malloc(sizeof(char *) * 5);
	while (++y != 4)
		tetri[y] = ft_strnew(4);
	tetri[y] = NULL;
	y = -1;
	while (++y != 4)
	{
		while (++x != 4)
			tetri[y][x] = '.';
		x = -1;
	}
	return (tetri);
}

char		**ft_copy_tetri(char **sample)
{
	char	**tetri;
	int		i;
	int		x;
	int		nb_hash;

	if (!(tetri = ft_emptygrid()))
	{
		ft_putendl("Malloc error");
		return (NULL);
	}
	nb_hash = 0;
	i = -1;
	while (++i != 4 && nb_hash != 4)
	{
		x = -1;
		while (++x != 4)
		{
			tetri[i][x] = sample[i][x];
			if (sample[i][x] == '#')
				nb_hash++;
		}
	}
	return (tetri);
}

char		**ft_gettetri(char **sample, int y)
{
	int		i;

	i = -1;
	while (sample[y][++i] != '#')
	{
		if (sample[y][i] == '\0')
		{
			sample++;
			i = -1;
		}
	}
	return (ft_copy_tetri(sample + y));
}

t_sample	*ft_treat_sample(char **sample)
{
	int			y;
	t_sample	*first_tetri;
	t_sample	*tmp;

	y = 0;
	if ((first_tetri = ft_newtetri(ft_gettetri(sample, y), y)))
	{
		tmp = first_tetri;
		y += 4;
		while (sample[y] != NULL)
		{
			if ((tmp->next = ft_newtetri(ft_gettetri(sample, y), y)))
				tmp = tmp->next;
			else
			{
				ft_putendl("Allocation error");
				return (NULL);
			}
			y += 4;
		}
	}
	else
		ft_putendl("Allocation eror");
	return (first_tetri);
}
