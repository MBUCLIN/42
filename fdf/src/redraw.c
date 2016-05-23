/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 18:11:37 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/23 14:22:13 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_img		*new_image(t_win *win)
{
	t_img		*cpy;

	if ((cpy = (t_img *)malloc(sizeof(t_img))) == NULL)
		return (NULL);
	cpy->data = NULL;
	cpy->img = NULL;
	if ((cpy->img = mlx_new_image(win->mlx, cpy->w, cpy->h)) == NULL)
	{
		del_img(win->mlx, cpy);
		return (NULL);
	}
	if ((cpy->data =\
	mlx_get_data_addr(win->mlx, &cpy->bpp, &cpy->slb, &cpy->endian)) == NULL)
	{
		del_img(win->mlx, cpy);
		return (NULL);
	}
	return (cpy);
}
