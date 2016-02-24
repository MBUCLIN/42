/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_integc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 16:13:20 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/24 17:24:50 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*apply_unsignedconv(size_t arg, int c, char *info)
{
	int		preci;

	preci = ft_getpreci(info);
	if (preci == 0 && arg == 0)
		return (ft_strdup(""));
	if (c == 'o' || c == 'O')
		return (ft_sitoabase(arg, "01234567"));
	else if (c == 'x')
		return (ft_sitoabase(arg, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_sitoabase(arg, "0123456789ABCDEF"));
	else
		return (ft_sitoabase(arg, "0123456789"));
	return (NULL);
}

static char		*apply_int(va_list ap, int c, char *info)
{
	int		arg;
	int		preci;

	arg = va_arg(ap, int);
	preci = ft_getpreci(info);
	if (preci == 0 && arg == 0)
		return (ft_strdup(""));
	if (c == 'd' || c == 'i')
		return (ft_itoa(arg));
	else if (c == 'o')
		return (ft_itoabase(arg, "01234567"));
	else if (c == 'x')
		return (ft_itoabase(arg, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_itoabase(arg, "0123456789ABCDEF"));
	else
		return (ft_itoabase(arg, "0123456789"));
	return (NULL);
}

char			*ft_apply_integc(char *info, int lm, int c, va_list ap)
{
	ssize_t		arg;

	arg = 0;
	if (lm == 216 || c == 'D' || c == 'O' || c == 'U')
		arg = va_arg(ap, long long);
	else if (lm == 208)
		arg = (char)va_arg(ap, int);
	else if (lm == 108)
		arg = va_arg(ap, long);
	else if (lm == 104)
		arg = (short)va_arg(ap, int);
	else if (lm == 106)
		arg = va_arg(ap, intmax_t);
	else if (lm == 122)
		arg = va_arg(ap, ssize_t);
	else
		return (apply_int(ap, c, info));
	if (c == 'o' || c == 'O' || c == 'x' || c == 'X' || c == 'u' || c == 'U')
		return (apply_unsignedconv(arg, c, info));
	else
		return (ft_sitoa(arg));
	return (NULL);
}
