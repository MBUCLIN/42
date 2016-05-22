/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 18:11:37 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/22 20:07:39 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			change_tile(t_iso *iso)
{
	iso->x /= 2;
	iso->y /= 2;
	return (1);
}

t_img		*reset_image(t_img *img, t_win *win)
{
	t_img		*cpy;

	if ((cpy = (t_img *)malloc(sizeof(t_img))) == NULL)
		return (NULL);
	cpy->data = NULL;
	cpy->img = NULL;
	ft_imgcpy(&cpy, img);
	if ((cpy->img = mlx_new_image(win->mlx, cpy->w, cpy->h)) == NULL)
	{
		end_fdf(NULL);
	}
	if ((cpy->data =\
	mlx_get_data_addr(win->mlx, &cpy->bpp, &cpy->slb, &cpy->endian)) == NULL)
	{
		end_fdf(NULL);
	}
	return (cpy);
}
