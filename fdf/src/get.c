/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 17:43:36 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/23 16:40:39 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				get_z(int *y, int x)
{
	return (y[x]);
}

t_iso			*get_tile(t_iso *iso, t_img *img)
{
	int			x;
	int			y;

	x = (img->w / img->x);
	y = (img->h / img->y);
	iso->x = x > y ? y : x;
	iso->y = iso->x;
	return (iso);
}
