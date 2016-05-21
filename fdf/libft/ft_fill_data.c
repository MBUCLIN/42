/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 17:21:07 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/21 17:28:26 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_fill_data(t_img **img, int x, int y, int color)
{
	char		*data;

	data = (*img)->data + ((x * (*img)->bpp) / 8 + (y * (*img)->slb));
	if (!(*img)->endian)
	{
		data[0] = (unsigned char)color;
		data[1] = (unsigned char)(color >> 8);
		data[2] = (unsigned char)(color >> 16);
	}
	else
	{
		data[0] = (unsigned char)(color >> 16);
		data[1] = (unsigned char)(color >> 8);
		data[2] = (unsigned char)(color);
	}
}
