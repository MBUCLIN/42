/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:14:33 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/21 20:30:18 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_iso			*initiate_iso()
{
	t_iso		*iso;

	if ((iso = (t_iso *)malloc(sizeof(t_iso))) == NULL)
	{
		ft_putendl_fd(2, "fdf: malloc error");
		return (NULL);
	}
	if ((iso->cdn = (t_cdn *)malloc(sizeof(t_cdn))) == NULL)
	{
		free(iso);
		ft_putendl_fd(2, "fdf: malloc error");
		return (NULL);
	}
	iso->color = 0xFF0000;
	iso->x = 64;
	iso->y = 32;
	iso->z1 = 0;
	iso->z2 = 0;
	iso->coef = 1;
	return (iso);
}

static void		set_image(t_img **img, t_list *map)
{
	(*img)->img = NULL;
	(*img)->data  = NULL;
	(*img)->y = ft_lstlen(map);
	(*img)->x = map->content_size;
	(*img)->bpp = 0;
	(*img)->slb = 0;
	(*img)->endian = 0;
	(*img)->h = 1280;
	(*img)->w = 1280;
}

t_img			*initiate_image(t_all *ev)
{
	void		*img;

	if ((ev->img = (t_img *)malloc(sizeof(t_img))) == NULL)
	{
		ft_putendl_fd(2, "fdf: malloc error");
		return (NULL);
	}
	set_image(&(ev->img), ev->map);
	if ((img = mlx_new_image(ev->win->mlx, ev->img->w, ev->img->h)) == NULL)
	{
		ft_putendl_fd(2, "fdf: image creation error");
		free(ev->img);
		return (NULL);
	}
	ev->img->img = img;
	ev->img->data = mlx_get_data_addr\
	(ev->img->img, &ev->img->bpp, &ev->img->slb, &ev->img->endian);
	return (ev->img);
}

t_win			*initiate_window()
{
	t_win		*win;

	if ((win = (t_win *)malloc(sizeof(t_win))) == NULL)
	{
		ft_putendl_fd(2, "fdf: malloc error");
		return (NULL);
	}
	if ((win->mlx = mlx_init()) == NULL)
	{
		ft_putendl_fd(2, "fdf: mlx init error");
		free(win);
		return (NULL);
	}
	if ((win->win = mlx_new_window(win->mlx, WIN_W, WIN_H, "fdf")) == NULL)
	{
		ft_putendl_fd(2, "fdf: window creation error");
		free(win);
		return (NULL);
	}
	win->pos_x = 0;
	win->pos_y = 0;
	return (win);
}

t_all			*initiate_mlx(t_all *ev)
{
	ev->img = NULL;
	ev->iso = NULL;
	if ((ev->win = initiate_window()) == NULL)
	{
		del_event(ev);
		return (NULL);
	}
	if ((ev->img = initiate_image(ev)) == NULL)
	{
		del_event(ev);
		return (NULL);
	}
	if ((ev->iso = initiate_iso()) == NULL)
	{
		del_event(ev);
		return (NULL);
	}
	return (ev);
}
