/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:53:08 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/21 18:28:53 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_is.h"

int		check_mod(const char *fmt, int i)
{
	int		good;
	int		i_cpy;

	good = 0;
	while(fmt[i])
	{
		if (fmt[i] == '%')
			good++;
		if (is_flag(fmt, i) || is_width(fmt, i) || is_preci(fmt, i) ||\
			is_lm(fmt, i))
			good++;
		if (is_conv(fmt, i))
			return (0);
		if (good == 0)
			return (i);
		good = 0;
		i++;
	}
	return (i);
}

char	*comv_mod(const char *fmt, int i, va_list ap)
{
	
}
