/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:10:24 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/27 15:10:54 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_conv(int c)
{
	int		ret;

	ret = 0;
	if ((ret = ft_is_int(c)) || (ret = ft_is_long(c)) ||\
		(ret = ft_is_char(c)) || (ret = ft_is_wconv(c)))
		return (ret);
	return (0);
}
