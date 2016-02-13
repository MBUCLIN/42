/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:52:09 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/10 16:25:42 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		after_conv(const char *fmt, int pos)
{
	if (fmt[pos + 1] == '%')
		return (pos + 1);
	while (fmt[pos])
	{
		if (ft_isconv(fmt[pos]))
			return (pos);
		pos++;
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
	ft_putendl(conv);
	lm = ft_get_lm(conv);
	if (ft_isconvc(conv[len] || conv[len] == '%'))
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

	st = 0;
	len = ft_strlen(fmt);
	while (fmt[++i])
		if (fmt[i] == '%' && fmt[i + 1] != '%' && ft_chkcv(fmt, i))
		{
			if (!(opt = ft_strjoindfree(opt, ft_strsub(fmt, st, i - st))))
				return (NULL);
			st = after_conv(fmt, i) + 1;
			if (!(opt = ft_strjoindfree(opt, get_conv(extcnv((fmt + i)), ap))))
				return (NULL);
			i = st;
		}
		else if (fmt[i] == '%')
		{
			i++;
			st = i;
		}
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
