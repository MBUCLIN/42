/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:40:06 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/28 13:32:39 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_conv(t_printf *inf, va_list ap)
{
	char	*conv;
	char	*nbr;

	conv = NULL;
	nbr = NULL;
	if (inf->flag)
		conv = ft_apply_flag(inf->flag, inf->c);
	nbr = ft_apply_conv(inf->c, ap);
	if (!(conv = ft_strjoindfree(conv, nbr)))
		return (NULL);
	return (conv);
}
