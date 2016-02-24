/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_wint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:18:26 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/24 15:18:28 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*ft_apply_wint(char *info, int adj, va_list ap)
{
	int		wint;
	int		n;
	char	*oct;

	oct = NULL;
	wint = va_arg(ap, int);
	n = ft_get_nbits(wint);
	if (!(oct = ft_getoct(wint, ft_getmask(n))))
		return (NULL);
	n = ft_get_noct(n);
	if (!(oct = ft_convoct(oct, n)))
		return (NULL);
	return (ft_apply_widtchar(info, oct, adj));
}