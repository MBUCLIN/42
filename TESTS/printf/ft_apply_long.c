/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 12:20:26 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/28 12:25:42 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_long(int c, va_list ap)
{
	long	arg;

	arg = va_arg(ap, long);
	if (c == 'D')
		return (ft_sitoa(arg));
	else if (c == 'U')
		return (ft_sitoabase(arg, "0123456789"));
	else if (c == 'O')
		return (ft_sitoabase(arg, "01234567"));
	return (NULL);
}
