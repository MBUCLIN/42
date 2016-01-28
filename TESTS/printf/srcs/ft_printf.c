/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:40:11 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/28 13:30:22 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int		after_conv(const char *fmt, int i)
{
	while (fmt[i])
	{
		if (ft_is_conv(fmt[i]))
			return (i + 1);
		i++;
	}
	return (i);
}

static char		*get_output(const char *fmt, va_list ap)
{
	int		i;
	int		start;
	char	*output;

	i = 0;
	start = i;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] != '%')
		{
			if (!(output = ft_strsub(fmt, start, i)))
				return (NULL);
//			if (!(output = ft_flags(fmt, output, i, ap)))
//				return (NULL);
			if (!(output = ft_conv(fmt, output, i, ap)))
				return (NULL);
			i = after_conv(fmt, i);
			start = i;
		}
		i++;
	}
	if (!(output = ft_strjoinfree(output, (fmt + start))))
		return (NULL);
	return (output);
}

int				ft_printf(const char *format, ...)
{
	int			size;
	char		*output;
	va_list		ap;

	va_start(ap, format);
	if (!(output = get_output(format, ap)))
		return (0);
	va_end(ap);
	size = ft_strlen(output);
	ft_putstr(output);
	free(output);
	return (size);
}
