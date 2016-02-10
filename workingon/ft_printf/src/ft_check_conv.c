/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:40:17 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/10 15:47:35 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_chkcv(const char *fmt, int i)
{
	while (fmt[++i])
	{
		if (fmt[i] == '%' || ft_isconv(fmt[i]))
			return (1);
		else if (!(ft_isflag(fmt[i])) && !(ft_iswidth(fmt, i)) &&\
				!(ft_ispreci(fmt[i])) && !(ft_islm((char *)(fmt + i))))
		{
			ft_putchar(fmt[i]);
			ft_putendl("	= fmt[i]");
			return (0);
		}
	}
	return (0);
}
