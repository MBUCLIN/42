/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:40:11 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/28 15:35:48 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

static int		check_conv(const char *fmt, int i)
{
	int		start;

	start = i + 1;
	while (fmt[i])
	{
		if (ft_is_conv(fmt[i]))
			return (1);
		else if (ft_is_flags(fmt[i]) || ft_is_preci(fmt[i]) ||\
			   	ft_is_width(fmt[i]) || ft_is_lm(fmt[i]))
			i++;
		else
			return (0);
	}
	return (0);
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
			if (!(output = ft_treat_conv(fmt, i, ap)))
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
