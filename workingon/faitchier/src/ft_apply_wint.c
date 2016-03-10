/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_wint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:19:55 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/10 16:01:30 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_printf		*ft_apply_wint(char *info, int adj, va_list ap)
{
	int			wint;
	int			n;
	char		*oct;
	t_printf	*conv;

	oct = NULL;
	if (!(conv = (t_printf *)malloc(sizeof(t_printf) * 1)))
		return (0);
	conv->opt = NULL;
	wint = va_arg(ap, int);
	n = ft_get_nbits(wint);
	if (!(oct = ft_getoct(wint, ft_getmask(n))))
		return (0);
	n = ft_get_noct(n);
	conv->size = n;
	if (!(conv->opt = ft_convoct(oct, n)))
		return (0);
	return (ft_apply_widtchar(info, conv, adj));
}
