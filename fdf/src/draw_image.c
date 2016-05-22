/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 12:33:03 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/22 17:33:54 by mbuclin          ###   ########.fr       */
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
	ft_printf("%d, %d == x\n", iso->cdn->x1, iso->cdn->x2);
	ft_printf("%d, %d == y\n", iso->cdn->y1, iso->cdn->y2);
	return (iso);
}

static int		get_z(int *y, int x)
{
	return (y[x]);
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
				ft_printf("%d, %d == z\n", (*ev)->iso->z1, (*ev)->iso->z2);
				(*ev)->iso = get_depart_point_line((*ev)->iso, i, j, -1);
				straight_line(&((*ev)->img), (*ev)->iso);
				ft_putendl("");
			}
			if (tmp->next)
			{
				(*ev)->iso = get_depart_point_line((*ev)->iso, i, j, 1);
				(*ev)->iso->z1 = get_z((int *)tmp->content, i);
				(*ev)->iso->z2 = get_z((int *)tmp->next->content, i);
				ft_printf("%d, %d == z\n", (*ev)->iso->z1, (*ev)->iso->z2);
				straight_line(&((*ev)->img), (*ev)->iso);
				ft_putendl("");
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
	if (fill_image(ev, (*ev)->map) == 0)
		end_fdf(*ev);
	mlx_put_image_to_window((*ev)->win->mlx, (*ev)->win->win,\
	(*ev)->img->img, (*ev)->win->pos_x, (*ev)->win->pos_y);
	return (1);	
}
