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

static void		ft_freetprintf(t_printf *inf)
{
	free(inf->conv);
	inf->flag = 0;
	inf->c = 0;
//	inf->fieldcar = 0;
//	inf->preci = 0;
//	inf->width = 0;
//	inf->lor = 0;
	free(inf);
}

static char		*extract_conv(const char *fmt, int i)
{
	int		j;

	j = i;
	while (fmt[i])
	{
		if (ft_is_conv(fmt[i]))
			return (ft_strsub(fmt, j, i - j + 1));
		i++;
	}
	return (NULL);
}

char			*ft_treat_conv(const char *fmt, int i, va_list ap)
{
	t_printf	*inf;
	char		*s;

	if (!(inf = (t_printf *)malloc(sizeof(t_printf))))
	{
		ft_freetprintf(inf);
		return (NULL);
	}
	if (!(inf->conv = extract_conv(fmt, i)))
	{
		ft_freetprintf(inf);
		return (NULL);
	}
	inf->flag = ft_get_flag(inf->conv);
	inf->c = inf->conv[ft_strlen(inf->conv) - 1];
	if (!(s = ft_conv(inf, ap)))
	{
		ft_freetprintf(inf);
		return (NULL);
	}
	ft_freetprintf(inf);
	return (s);
}
