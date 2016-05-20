/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:14:33 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/20 16:28:47 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		set_image(t_img **img, t_list *map)
{
	(*img)->img = NULL;
	(*img)->data  = NULL;
	(*img)->y = ft_lstlen(map);
	(*img)->x = map->content_size;
	(*img)->bpp = 0;
	(*img)->slb = 0;
	(*img)->endian = 0;
	(*img)->h = y * 32;
	(*img)->w = x * 64;
}

t_win		*initiate_image(t_all *ev)
{
	void		*img;

	if ((ev->img = (t_img *)malloc(sizeof(t_img))))
	{
		ft_putendl_fd(2, "fdf: malloc error");
		return (NULL);
	}
	set_image(&(ev->img), ev->map);
	if ((img = mlx_new_image(ev->win->mlx, ev->img->w, ev->img->h)) == NULL)
	{
		ft_putendl_fd(2, "fd: image creation error");
		free(ev->img);
		return (NULL);
	}
	ev->img->img = img;
	ev->img->data = mlx_get_data_addr\
	(ev->img->img, &ev->img->bpp, &ev->img->slp, &ev->img->endian);
	return (ev->img);
}

t_win		*initiate_window()
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
	return (win);
}

t_all		*initiate_mlx(t_all *ev)
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
	return (ev);
}
