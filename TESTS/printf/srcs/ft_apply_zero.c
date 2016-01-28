/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:58:31 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/28 14:25:02 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_apply_zero(const char *fmt, int i)
{
	int		size;
	int		sizew;

	size = ft_get_preci(fmt, i);
	sizew = ft_get_width(fmt, i);
	if (size < sizew)
		size = sizew;
	
}
