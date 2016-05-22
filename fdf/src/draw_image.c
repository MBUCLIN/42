/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 12:33:03 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/22 20:23:44 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		calcul_iso(int x, int y, t_iso *iso, int xy)
{
	int		ret;

	ret = 0;
	if (xy == -1)
		ret = (x - y) * (iso->x / 2);
	else if (xy == 1)
		ret = ((x + y) * (iso->y / 2));
	else if (xy == 2)
		ret = ((x + y) * (iso->y / 2));
	return (ret);
}

t_iso	*get_depart_point_line(t_iso *iso, int i, int j, int n)
{
	iso->cdn->x1 = calcul_iso(i, j, iso, -1) + WIN_W / 2;
	iso->cdn->y1 = calcul_iso(i, j, iso, 1) + WIN_H / 2;
	if (n == -1)
		iso->cdn->x2 = calcul_iso(i + 1, j, iso, -1) + WIN_W / 2;
	else
		iso->cdn->x2 = calcul_iso(i, j + 1, iso, -1) + WIN_W / 2;
	if (n == -1)
		iso->cdn->y2 = calcul_iso(i + 1, j, iso, 2) + WIN_H / 2;
	else
		iso->cdn->y2 = calcul_iso(i, j + 1, iso, 2) + WIN_H / 2;
	return (iso);
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
				(*ev)->iso = get_depart_point_line((*ev)->iso, i, j, -1);
				if (!straight_line(&((*ev)->img), (*ev)->iso))
					return (0);
			}
			if (tmp->next)
			{
				(*ev)->iso->z1 = get_z((int *)tmp->content, i);
				(*ev)->iso->z2 = get_z((int *)tmp->next->content, i);
				(*ev)->iso = get_depart_point_line((*ev)->iso, i, j, 1);
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
		change_tile((*ev)->iso);
		if ((img = reset_image((*ev)->img, (*ev)->win)) == NULL)
			end_fdf(*ev);
		del_img((*ev)->win->mlx, (*ev)->img);
		(*ev)->img = img;
		return (draw_image(ev));
	}
	mlx_put_image_to_window((*ev)->win->mlx, (*ev)->win->win,\
	(*ev)->img->img, (*ev)->win->pos_x, (*ev)->win->pos_y);
	return (1);	
}
