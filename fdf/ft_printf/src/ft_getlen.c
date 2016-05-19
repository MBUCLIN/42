/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:16:24 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/10 12:16:25 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_getlen(const char *fmt)
{
	int		i;

	i = -1;
	while (fmt[++i])
		if (fmt[i] == '%' && ft_checkconv(fmt, i))
			return (i);
	return (i);
}
