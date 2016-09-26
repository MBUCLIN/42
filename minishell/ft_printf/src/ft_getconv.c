/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:15:35 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/17 14:40:39 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_printf		*apply_conv(t_printf *conv, char *info, int lm, va_list ap)
{
	if (!(conv = ft_apply_conv(info, lm, ap)))
	{
		free(info);
		return (NULL);
	}
	free(info);
	return (conv);
}

t_printf			*ft_getconv(char *info, va_list ap)
{
	int			lm;
	int			c;
	t_printf	*conv;

	conv = NULL;
	if (info == NULL)
		return (NULL);
	c = ft_strlenp(info) - 1;
	lm = ft_get_lm(info);
	if (ft_isconvc(info[c]))
		return (apply_conv(conv, info, lm, ap));
	if (!(conv = ft_apply_number(info, ap, lm)))
	{
		free(info);
		return (NULL);
	}
	if (!(conv = ft_apply_flagsi(info, conv)))
	{
		free(info);
		return (NULL);
	}
	free(info);
	return (conv);
}
