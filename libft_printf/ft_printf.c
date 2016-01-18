/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 14:29:27 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/18 15:46:14 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_is.h"

static int		add_part(/*va_list ap,*/ char *output, const char *format, int i)
{
	int		start;
//	char	*conv;

	start = i;
	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] == '%' || format[i - 1] == '%'))
			break ;
		i++;
	}
	output = ft_strjoindfree(output, ft_strsub(format, start, (i - 1) - start));
//	conv = treat_conv((format + i), ap);
	i = i + 2;
	return (i);
}

static int		get_modn(const char *format)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] != '%' && format[i - 1] != '%'))
			n++;
		i++;
	}
	return (n);
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
		i = add_part(/*ap, */output, format, i);
		n--;
	}
	va_end(ap);
	ft_putendl(output);
	return (1);
}
