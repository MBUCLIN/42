/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:45:26 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/28 12:25:56 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_apply_conv(int c, va_list ap)
{

	if (ft_is_int(c))
		return (ft_apply_int(c, ap));
	else if (ft_is_long(c))
		return (ft_apply_long(c, ap));
//	else if (ft_is_char(c))
//		return (ft_apply_char(c, ap));
//	else if (ft_is_wconv(c))
//		return (ft_apply_wconv(c, ap));
	return (NULL);
}
