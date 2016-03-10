/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:19:13 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/10 13:51:15 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_checkconv(const char *fmt, int i)
{
	while (fmt[++i])
		if (ft_isconv(fmt[i]))
			return (1);
	return (0);
}
