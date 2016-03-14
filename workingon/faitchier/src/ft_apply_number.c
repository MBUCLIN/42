/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:20:16 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/14 18:21:20 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_printf	*apply_unsignedconv(t_printf *conv, size_t arg, char c)
{
	if (c == 'o' || c == 'O')
		conv->opt = ft_sitoabase(arg, "01234567");
	else if (c == 'x')
		conv->opt = ft_sitoabase(arg, "0123456789abcdef");
	else if (c == 'X')
		conv->opt = ft_sitoabase(arg, "0123456789ABCDEF");
	else
		conv->opt = ft_sitoabase(arg, "0123456789");
	if (conv->opt == NULL)
		return (NULL);
	conv->size = ft_strlen(conv->opt);
	return (conv);
}

static ssize_t	get_arg(int lm, char c, va_list ap)
{
	ssize_t		arg;

	arg = 0;
	if (lm == 216)
		arg = va_arg(ap, long long);
	else if (lm == 108 || c == 'D' || c == 'U' || c == 'O')
		arg = va_arg(ap, long);
	else if (lm == 106)
		arg = va_arg(ap, intmax_t);
	else if (lm == 122)
		arg = va_arg(ap, ssize_t);
	return (arg);
}

t_printf		*apply_ssize_t(t_printf *conv, char *info, va_list ap, int lm)
{
	ssize_t		arg;
	int			preci;
	int			c;

	c = info[ft_strlen(info) - 1];
	arg = get_arg(lm, c, ap);
	preci = ft_getpreci(info);
	if (preci == 0 && arg == 0)
	{
		if (!(conv->opt = ft_strdup("")))
			return (NULL);
		conv->size = 1;
		return (conv);
	}
	if (c == 'o' || c == '0' || c == 'x' || c == 'u' || c == 'U' || c == 'X')
		return (apply_unsignedconv(conv, arg, c));
	if (!(conv->opt = ft_sitoa(arg)))
		return (NULL);
	conv->size = ft_strlen(conv->opt);
	return (conv);
}

t_printf		*ft_apply_number(char *info, va_list ap, int lm)
{
	t_printf	*conv;
	int			c;

	c = info[ft_strlen(info) - 1];
	if (!(conv = (t_printf *)malloc(sizeof(t_printf) * 1)))
		return (NULL);
	if ((c == 'D' || c == 'U' || c == 'O') ||\
		(lm == 122 || lm == 106 || lm == 108 || lm == 216))
		return (apply_ssize_t(conv, info, ap, lm));
	return (ft_apply_int(conv, info, ap, lm));
}
