/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:53:08 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/26 14:43:47 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_is.h"

int		check_mod(const char *fmt, int i)
{
	int		good;
	int		i_cpy;

	good = 0;
	while(fmt[i])
	{
		if (fmt[i] == '%')
			good++;
		if (is_flag(fmt, i) || is_width(fmt, i) || is_preci(fmt, i) ||\
			is_lm(fmt, i))
			good++;
		if (is_conv(fmt, i))
			return (0);
		if (good == 0)
			return (i);
		good = 0;
		i++;
	}
	return (i);
}

char	*fill_conv(char *extr, int size)
{
	char	*conv;

	if (!(conv = apply_flags(extr, size, conv)))
		return (NULL);
}

int		get_size(char *mod)
{
	int		preci;
	int		width;
	int		i;

	i = -1;
	preci = 0;
	width = 0;
	while (mod[++i] && !preci)
		preci = is_preci(mod, i);
	i = -1;
	while (mod[++i] && !width)
		width = is_width(mod, i);
	if (!width && !preci)
		return (0);
	if (width > preci)
		return (width);
	else
		return (preci);
}

char	*extract_conv(const char *fmt, int i)
{
	char	*extr;
	int		start;

	start = i;
	while (fmt[i])
	{
		if (is_conv(fmt, i))
			return (ft_strsub(fmt, start, i));
		i++;
	}
	if (!(extr = ft_memalloc(sizeof(char) * 1)))
		return NULL;
	return (extr);
}

char	*conv_mod(const char *fmt, int i, va_list ap)
{
	char	*extr;
	int		size;

	size = 0;
	if (!(extr = extract_conv(fmt, i)))
		return (NULL);
	if (extr[0] != 0)
		size = get_size(extr);
	else
		free(extr);
	return (fill_conv(extr, size));
}
