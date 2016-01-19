/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:47:51 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/19 15:49:42 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_is.h"

int		get_nmod(int mod, const char *format)
{
	int		i;
	int		n;

	i = ft_strlen(format) - 1;
	n = 0;
	while (format[i])
	{
		if (format[i] == '%' && (format[i + 1] != '%' && format[i - 1] != '%'))
			n++;
		if (n == mod)
			return (i);
		i--;
	}
	return (i);
}

int		get_modn(const char *format)
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
