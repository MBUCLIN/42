/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 12:33:03 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/23 16:21:02 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		calcul_iso(int x, int y, t_iso *iso, int xy)
{
	int		ret;

	ret = 0;
	if (xy == -1)
		ret = (x - y) * ((iso->coef * iso->x) / 2);
	else if (xy == 1)
		ret = ((x + y) * ((iso->coef * iso->y) / 2));
	else if (xy == 2)
		ret = ((x + y) * ((iso->coef * iso->y) / 2));
	return (ret);
}

t_iso	*get_depart_point_line(t_all *ev, int i, int j, int n)
{
	ev->iso->cdn->x1 = calcul_iso(i, j, ev->iso, -1) + ev->img->w / 2;
	ev->iso->cdn->y1 = calcul_iso(i, j, ev->iso, 1) + ev->img->h / 2;
	if (n == -1)
		ev->iso->cdn->x2 = calcul_iso(i + 1, j, ev->iso, -1) + ev->img->w / 2;
	else
		ev->iso->cdn->x2 = calcul_iso(i, j + 1, ev->iso, -1) + ev->img->w / 2;
	if (n == -1)
		ev->iso->cdn->y2 = calcul_iso(i + 1, j, ev->iso, 2) + ev->img->h / 2;
	else
		ev->iso->cdn->y2 = calcul_iso(i, j + 1, ev->iso, 2) + ev->img->h / 2;
	return (ev->iso);
}

int		fill_image(t_all **ev, t_list *map)
{
	t_list		*tmp;
	int			i;
	int			j;

	tmp = map;
	j = 0;
	while (tmp)
	{
		i = 0;
		while ((unsigned long)i < (tmp->content_size / sizeof(int)))
		{
			if ((unsigned long)(i + 1) != tmp->content_size / sizeof(int))
			{
				(*ev)->iso->z1 = get_z((int *)tmp->content, i);
				(*ev)->iso->z2 = get_z((int *)tmp->content, i + 1);
				(*ev)->iso = get_depart_point_line((*ev), i, j, -1);
				if (!straight_line(&((*ev)->img), (*ev)->iso))
					return (0);
			}
			if (tmp->next)
			{
				(*ev)->iso->z1 = get_z((int *)tmp->content, i);
				(*ev)->iso->z2 = get_z((int *)tmp->next->content, i);
				(*ev)->iso = get_depart_point_line((*ev), i, j, 1);
				if (!straight_line(&((*ev)->img), (*ev)->iso))
					return (0);
			}
			i++;
		}
		tmp = tmp->next;
		j++;
	}
	return (1);
}

int		draw_image(t_all **ev)
{
	t_img		*img;

	img = NULL;
	if (fill_image(ev, (*ev)->map) == 0)
	{
		ft_putendl("Img too little");
		end_fdf(*ev);
	}
	mlx_put_image_to_window((*ev)->win->mlx, (*ev)->win->win,\
	(*ev)->img->img, (*ev)->win->pos_x, (*ev)->win->pos_y);
	return (1);	
}
