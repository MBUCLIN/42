/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:40:06 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/27 15:14:06 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_nconv(const char *fmt)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (fmt)
		while (fmt[i])
		{
			if (fmt[i] == '%' && fmt[i + 1] != '%')
				n++;
		}
	return (n);
}

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
