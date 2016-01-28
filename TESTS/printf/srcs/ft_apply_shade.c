/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_shade.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:52:21 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/28 13:58:19 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*ft_apply_shade(const char *fmt, int i)
{
	int		c;
	int		j;

	j = i;
	while (fmt[++i])
		if ((c = ft_is_conv(fmt[i])))
			break ;
	if (c == 'o')
		return (ft_strdup("0"));
	else if (c == 'x')
		return (ft_strdup("0x"));
	else if (c == 'X')
		return (ft_strdup("0X"));
	return (NULL);
}
