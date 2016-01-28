/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:28:58 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/28 15:43:16 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*extract_conv(const char *fmt, int i)
{
	int		j;

	j = i;
	while (fmt[i])
	{
		if (ft_is_conv(fmt[i]))
			return (ft_strsub(fmt, j, i));
		i++;
	}
	return (NULL);
}

char			*ft_treat_conv(const char *fmt, int i, va_list ap)
{
	t_printf	opt;
	char		*conv;

	if (!(conv = extract_conv(fmt, i)))
		return (NULL);
	ft_putstr(conv);
	free(conv);
	return (NULL);
}
