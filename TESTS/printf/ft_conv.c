/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:40:06 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/28 12:45:24 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv(const char *fmt, char *opt, int i, va_list ap)
{
	char	*conv;
	int		c;

	while (fmt[i])
	{
		if ((c = ft_is_conv(fmt[i])))
		{
			if (!(conv = ft_apply_conv(c, ap)))
				return (NULL);
			if (!(opt = ft_strjoindfree(opt, conv)))
				return (NULL);
			break ;
		}
		i++;
	}
	return (opt);
}
