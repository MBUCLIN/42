/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:52:02 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/28 12:24:10 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*ft_apply_int(int c, va_list ap)
{
	int		arg;

	arg = va_arg(ap, int);
	if (c == 'd' || c == 'i')
		return (ft_sitoa(arg));
	else if (c == 'u')
		return (ft_sitoabase(arg, "0123456789"));
	else if (c == 'o')
		return (ft_sitoabase(arg, "01234567"));
	else if (c == 'x')
		return (ft_sitoabase(arg, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_sitoabase(arg, "0123456789ABCDEF"));
	return (NULL);
}
