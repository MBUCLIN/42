/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 14:28:38 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/22 17:35:39 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			few_x_for_one_y(t_img **img, t_iso *iso, t_cdn *c)
{
	int		x;
	int		y;

	if (!check_coordonne(iso->cdn))
		return (0);
	if (c->x1 > c->x2)
	{
		ft_swap(&c->x1, &c->x2);
		ft_swap(&c->y1, &c->y2);
	}
	x = c->x1;
	y = c->y1;
	while (x <= c->x2)
	{
		y = c->y1 + ((c->y2 - c->y1) * (x - c->x1)) / (c->x2 - c->x1);
		ft_fill_data(img, x, y, iso->color);
		x++;
	}
	return (1);
}

int			few_y_for_one_x(t_img **img, t_iso *iso, t_cdn *c)
{
	int		x;
	int		y;

	if (!check_coordonne(iso->cdn))
		return (0);
	if (c->y1 > c->y2)
	{
		ft_swap(&c->x1, &c->x2);
		ft_swap(&c->y1, &c->y2);
	}
	x = c->x1;
	y = c->y1;
	while (y <= c->y2)
	{
		x = c->x1 + ((c->x2 - c->x1) * (y - c->y1)) / (c->y2 - c->y1);
		ft_fill_data(img, x, y, iso->color);
		y++;
	}
	return (1);
}

static int	substract_z(t_cdn *cdn, t_iso *iso)
{
	cdn->y1 -= iso->coef * (iso->z1 * iso->y);
	cdn->y2 -= iso->coef * (iso->z2 * iso->y);
	return (1);
}

int			straight_line(t_img **img, t_iso *iso)
{
	int		absx;
	int		absy;

	absx = FT_ABS(iso->cdn->x2 - iso->cdn->x1);
	absy = FT_ABS(iso->cdn->y2 - iso->cdn->y1);
	if (absx <= absy)
	{
		substract_z(iso->cdn, iso);
		if (!few_x_for_one_y(img, iso, iso->cdn))
			return (0);
	}
	else
	{
		substract_z(iso->cdn, iso);
		if (!few_y_for_one_x(img, iso, iso->cdn))
			return (0);
	}
	return (1);
}
