/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:20:02 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/17 15:46:53 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_printf	*apply_hconv(t_printf *conv, int a, char c, int lm)
{
	if (lm == 'h')
	{
		if (c == 'o')
			conv->opt = ft_sitoabase((unsigned short)a, "01234567");
		else if (c == 'x')
			conv->opt = ft_sitoabase((unsigned short)a, "0123456789abcdef");
		else if (c == 'X')
			conv->opt = ft_sitoabase((unsigned short)a, "0123456789ABCDEF");
		else
			conv->opt = ft_sitoabase((unsigned short)a, "0123456789");
	}
	else
	{
		if (c == 'o')
			conv->opt = ft_sitoabase((unsigned char)a, "01234567");
		else if (c == 'x')
			conv->opt = ft_sitoabase((unsigned char)a, "0123456789abcdef");
		else if (c == 'X')
			conv->opt = ft_sitoabase((unsigned char)a, "013456789ABCDEF");
		else
			conv->opt = ft_sitoabase((unsigned char)a, "0123456789");
	}
	conv->size = ft_strlen(conv->opt);
	return (conv);
}

static t_printf	*apply_unsignedconv(t_printf *conv, int a, char c, int lm)
{
	if (lm == 'h' || lm == 208)
		return (apply_hconv(conv, a, c, lm));
	else if (c == 'o')
		conv->opt = ft_sitoabase((unsigned int)a, "01234567");
	else if (c == 'x')
		conv->opt = ft_sitoabase((unsigned int)a, "0123456789abcdef");
	else if (c == 'X')
		conv->opt = ft_sitoabase((unsigned int)a, "0123456789ABCDEF");
	else
		conv->opt = ft_sitoabase((unsigned int)a, "0123456789");
	return (conv);
}

static int		get_arg(int lm, va_list ap)
{
	int		arg;

	arg = 0;
	if (lm == 208)
		arg = (char)va_arg(ap, int);
	else if (lm == 104)
		arg = (short)va_arg(ap, int);
	else
		arg = va_arg(ap, int);
	return (arg);
}

t_printf		*ft_apply_int(t_printf *conv, char *info, va_list ap, int lm)
{
	int		arg;
	int		preci;
	int		c;

	c = info[ft_strlen(info) - 1];
	preci = ft_getpreci(info);
	arg = get_arg(lm, ap);
	if (preci == 0 && arg == 0)
	{
		if (!(conv->opt = ft_strdup("")))
			return (NULL);
		conv->size = 1;
		return (conv);
	}
	if (c == 'o' || c == 'x' || c == 'X' || c == 'u')
		return (apply_unsignedconv(conv, arg, c, lm));
	else
	{
		if (!(conv->opt = ft_sitoa((int)arg)))
			return (NULL);
	}
	conv->size = ft_strlen(conv->opt);
	return (conv);
}
