/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:17:25 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/22 19:43:55 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		del_map(void *y, size_t size)
{
	free(y);
	size = 0;
	y = NULL;
}

void		del_iso(t_iso *iso)
{
	if (iso)
	{
		if (iso->cdn)
			free(iso->cdn);
		free(iso);
	}
}

void		del_img(void *mlx, t_img *img)
{
	if (img)
	{
		mlx_destroy_image(mlx, img->img);
		free(img);
		img = NULL;
	}
}

void		del_win(t_win *win)
{
	if (win)
	{
		mlx_destroy_window(win->mlx, win->win);
		free(win);
	}
}

void		del_event(t_all *ev)
{
	if (ev)
	{
		if (ev->map)
			ft_lstdel(&(ev->map), &del_map);
		if (ev->iso)
			del_iso(ev->iso);
		if (ev->img)
			del_img(ev->win->mlx, ev->img);
		if (ev->win)
			del_win(ev->win);
		free(ev);
	}
}
