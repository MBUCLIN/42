/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 17:43:36 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/24 16:52:40 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				get_z(int *y, int x)
{
	return (y[x]);
}

int				get_max_z(t_list *map)
{
	int			i;
	t_list		*tmp;
	int			z;
	int			t;

	tmp = map;
	z = 0;
	while (tmp)
	{
		i = 0;
		while ((unsigned long)i < map->content_size / sizeof(int))
		{
			if (z < (t = FT_ABS(get_z((int *)tmp->content, i))))
				z = t;
			i++;
		}
		tmp = tmp->next;
	}
	return (z);
}

t_iso			*get_tile(t_iso *iso, t_img *img)
{
	int			x;
	int			y;

	x = (img->w / img->x);
	y = (img->h / img->y);
	if (x > 60)
		x = x / 2;
	else if (y > 60)
		y = y / 2;
	iso->x = x > y ? y : x;
	iso->y = iso->x;
	return (iso);
}
