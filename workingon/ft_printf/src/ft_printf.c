/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:52:09 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/18 15:48:18 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		after_conv(const char *fmt, int pos)
{
	while (fmt[++pos])
	{
		if (ft_isconv(fmt[pos]) || fmt[pos] == '%')
			return (pos);
	}
	return (pos);
}

static char		*extcnv(const char *start)
{
	int				i;

	i = 0;
	while (start[++i])
	{
		if (ft_isconv(start[i]) || start[i] == '%')
			return (ft_strsub(start, 0, i + 1));
	}
	return (NULL);
}

static char		*get_conv(char *conv, va_list ap)
{
	char			*ret;
	int				lm;
	int				len;

	len = ft_strlen(conv) - 1;
	ret = NULL;
	if (conv == NULL)
		return (NULL);
	lm = ft_get_lm(conv);
	if (ft_isconvc(conv[len]) || conv[len] == '%' || conv[len] == 'p')
		return (ft_apply_conv(conv, ap, lm));
	if (ft_isconvi(conv[len]))
		if (!(ret = ft_apply_integc(lm, conv[len], ap)))
			return (NULL);
	if (!(ret = ft_apply_flagsi(conv, ret)))
		return (NULL);
	return (ret);
}

static char		*get_opt(const char *fmt, char *opt, va_list ap, int i)
{
	int				st;
	int				len;

	st = -1;
	len = ft_strlen(fmt);
	while (fmt[++i])
		if (fmt[i] == '%' && ft_chkcv(fmt, i))
		{
			st += 1;
			if (!(opt = ft_strjoindfree(opt, ft_strsub(fmt, st, i - st))))
				return (NULL);
			st = after_conv(fmt, i);
			if (!(opt = ft_strjoindfree(opt, get_conv(extcnv((fmt + i)), ap))))
				return (NULL);
			i = st;
		}
	st += 1;
	if (!(opt = ft_strjoindfree(opt, ft_strsub(fmt, st, len - st))))
		return (NULL);
	return (opt);
}

int				ft_printf(const char *format, ...)
{
	char			*opt;
	va_list			ap;
	int				size;

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
