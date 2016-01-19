/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 14:29:27 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/19 16:46:20 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_is.h"

static char		*add_part(char *input, const char *format, int i)
{
	int		start;
	char	*output;

	start = i;
	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] != '%' && format[i - 1] != '%'))
			break ;
		i++;
	}
	if (!(output = ft_strjoindfree(input, ft_strsub(format, start, i - start))))
		return (NULL);
	ft_putstr("output = ");
	ft_putendl(output);
	ft_putendl("");
	return (output);
}

static char		*conv_mod(char *input, const char *format, int i, va_list ap)
{
	char	flag;
	char	*add;
	char	width;
	char	presi;

	if (flag = get_flag(format, i))
		if (!(add = apply_flag(add, flag, ap)))
			return (NULL);
	if (width = get_width(format, i))
		if (!(add = apply_width(add, width, ap)))
			return (NULL);
	if (preci = get_preci(format, i))
		if (!(add = apply_preci(add, presi, ap)))
			return (NULL);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			n;
	int			i;
	char		*output;

	i = 0;
	output = NULL;
	n = get_modn(format);
	va_start(ap, format);
	while (n > 0)
	{
		if (!(output = add_part(output, format, i)))
			return (0);
		i = get_nmod(n, format);
		if (!(output = conv_mod(output, format, i)))
			return (0);
		n--;
	}
	va_end(ap);
	ft_putstr(output);
	free(output);
	return (1);
}
