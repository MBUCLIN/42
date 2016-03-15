/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_wint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:19:55 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/15 13:49:56 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

t_printf		*ft_apply_wint(char *info, int adj, va_list ap)
{
	int			wint;
	int			n;
	char		*oct;
	t_printf	*conv;

	if (!(conv = (t_printf *)malloc(sizeof(t_printf) * 1)))
		return (NULL);
	wint = va_arg(ap, int);
	if (wint == 0)
	{
		if (!(conv->opt = ft_strdup("")))
			return (NULL);
		conv->size = 1;
	}
	else
	{
		n = ft_get_nbits(wint);
		if (!(oct = ft_getoct(wint, ft_getmask(n))))
			return (NULL);
		n = ft_get_noct(n);
		conv->size = n;
		if (!(conv->opt = ft_convoct(oct, n)))
			return (NULL);
	}
	return (ft_apply_widtchar(info, conv, adj));
}
