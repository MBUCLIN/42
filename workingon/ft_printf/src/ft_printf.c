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

#include "../includes/ft_printf.h"

static char		*extcnv(const char *start)
{
	int		i;

	i = 0;
	while (start[i])
	{
		if (ft_isconv(start[i]))
			return (ft_strsub(start, 0, i + 1));
		i++;
	}
	return (NULL);
}

static char		*get_conv(char *conv, va_list ap)
{
	char			*ret;
	int				lm;

	ret = NULL;
	if (conv == NULL)
		return (NULL);
/*
**	if (ft_isconvc(conv[ft_strlen(conv) - 1]))
**	{
**		if (!(ret = ft_apply_carc(conv, ap)))
**			return (NULL);
**		if (!(ret = ft_apply_flagsc(conv, ret)))
**			return (NULL);
**	}
*/
/*
**	if
**	{
*/
	lm = ft_get_lm(conv);
	if (!(ret = ft_apply_integc(lm, conv[ft_strlen(conv) - 1], ap)))
		return (NULL);
	if (!(ret = ft_apply_flagsi(conv, ret)))
		return (NULL);
//	}
	return (ret);
}

static char		*get_opt(const char *fmt, char *opt, va_list ap, int i)
{
	int		st;
	int		len;

	st = 0;
	len = ft_strlen(fmt);
	while (fmt[++i])
		if (fmt[i] == '%' && fmt[i + 1] != '%' && check_conv(fmt, i))
		{
			if (!(opt = ft_strjoindfree(opt, ft_strsub(fmt, st, i - st))))
				return (NULL);
			i = ft_after_conv(fmt, i);
			st = i + 1;
			if (!(opt = ft_strjoindfree(opt, get_conv(extcnv((fmt + i)), ap))))
				return (NULL);
		}
		else if (fmt[i] == '%')
		{
			i = ft_after_conv(fmt, i) + 1;
			if (!(opt = ft_strjoindfree(opt, ft_strsub(fmt, st, i - st))))
				return (NULL);
			st = i;
		}
	if (!(opt = ft_strjoindfree(opt, ft_strsub(fmt, st, len - st))))
		return (NULL);
	return (opt);
}

int		ft_printf(const char *format, ...)
{
	char		*opt;
	va_list		ap;
	int			size;

	opt = NULL;
	va_start(ap, format);
	if (!(opt = get_opt(format, opt, ap, -1)))
		return (0);
	size = ft_strlen(opt);
	ft_putstr(opt);
	ft_memset(opt, 0, ft_strlen(opt));
	free(opt);
	return (size);
}
