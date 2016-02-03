/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:52:09 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/03 16:30:28 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		after_conv(const char fmt, int pos)
{
	while (fmt[pos])	
	{
		if (ft_isconv(fmt[pos]))
			return (pos);
		pos++;
	}
	return (pos);
}

static char		*extract_conv(char *start)
{
	int		i;

	i = 0;
	while (start[i])
	{
		if (ft_isconv(start[i]))
			return (ft_strsub(start, 0, i));
		i++;
	}
	return (NULL);
}

static char		*get_conv(char *conv)
{
	unsigned char	info;
	char			*ret;

	if (!(ret = ft_apply_conv(conv[ft_strlen(conv) - 1])))
		return (NULL);
	return (ret);
}

static char		*get_opt(const char *fmt, va_list ap)
{
	char	*opt;
	int		i;
	int		start;
	char	*extr;

	i = 0;
	start = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] != '%')
		{
			if (!(opt = ft_strjoindfree(opt, ft_strsub(fmt, start, i - start))))
				return (NULL);
			if (!(extr = extract_conv((fmt + i))))
				return (NULL);
			i = after_conv(format, i);
			start = i;
			if (!(opt = ft_strjoindfree(opt, get_conv(extr))))
				return (NULL);
		}
		i++;
	}
	if (!(opt = ft_strjoindfree(opt, ft_strsub(fmt, start, i))))
		return (NULL);
	return (opt);
}

int		ft_printf(const char *format, ...)
{
	char		*opt;
	va_list		ap;
	int			size;

	va_start(ap, format);
	if (!(opt = get_opt(format, ap)))
		return (0);
	size = ft_strlen(opt);
	ft_putstr(opt);
	free(opt);
	return (size);
}
