/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_keyevent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:30:45 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/23 18:02:19 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		end_fdf(t_all *ev)
{
	del_event(ev);
	exit(1);
}

void		moove_image(int way, t_all *ev)
{
	if (way == 126)
		ev->win->pos_y -= 100;
	else if (way == 125)
		ev->win->pos_y += 100;
	else if (way == 124)
		ev->win->pos_x += 100;
	else
		ev->win->pos_x -= 100;
	mlx_clear_window(ev->win->mlx, ev->win->win);
	mlx_put_image_to_window\
	(ev->win->mlx, ev->win->win, ev->img->img, ev->win->pos_x, ev->win->pos_y);
}

void		zoom_in(t_all *ev)
{
	int			h;
	int			w;

	if (ev->iso->coef < 8)
	{
		h = ev->img->h;
		w = ev->img->w;
		ev->img->h = h * 2;
		ev->img->w = w * 2;
		mlx_clear_window(ev->win->mlx, ev->win->win);
		mlx_destroy_image(ev->win->mlx, ev->img->img);
		ev->img->img = mlx_new_image(ev->win->mlx, w * 2, h * 2);
		ev->img->data = NULL;
		ev->img->data = mlx_get_data_addr\
		(ev->img->img, &ev->img->bpp, &ev->img->slb, &ev->img->endian);
		ev->iso->coef *= 2;
		ev->win->pos_x -= w / 2;
		ev->win->pos_y -= h / 2;
		draw_image(&ev);
	}
	
}

void		zoom_out(t_all *ev)
{
	int		h;
	int		w;

	if (ev->iso->coef > 1)
	{
		h = ev->img->h / 2;
		w = ev->img->w / 2;
		ev->img->h /= 2;
		ev->img->w /= 2;
		mlx_clear_window(ev->win->mlx, ev->win->win);
		mlx_destroy_image(ev->win->mlx, ev->img->img);
		ev->img->img = mlx_new_image(ev->win->mlx, w, h);
		ev->img->data = NULL;
		ev->img->data = mlx_get_data_addr\
		(ev->img->img, &ev->img->bpp, &ev->img->slb, &ev->img->endian);
		ev->iso->coef /= 2;
		ev->win->pos_x += w / 2;
		ev->win->pos_y += h / 2;
		draw_image(&ev);
	}
}

int			key_event(int keycode, t_all *ev)
{
	if (keycode == 53 || keycode == 12)
		end_fdf(ev);
	else if (keycode > 122 && keycode < 127)
		moove_image(keycode, ev);
	else if (keycode == 69)
		zoom_in(ev);
	else if (keycode == 78)
		zoom_out(ev);
	else
		ft_printf("keycode : %d\n", keycode);
	return (0);
}
