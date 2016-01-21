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

char			*get_output(const char *format, va_list ap, int n)
{
	int		i;
	char	*conv;
	char	*output;

	i = 0;
	while (n > 0)
	{
		if (!(output = add_part(output, format, i)))
			return (NULL);
		i = get_nmod(n, format);
		if (!(check_mod))
		{
			if (!(output = bad_mod_cpy(output, format, i)))
				return (NULL);
		}
		else
		{
			if (!(conv = conv_mod(format, i, ap)))
				return (NULL);
			if (!(output = ft_strjoindfree(output, conv)))
				return (NULL);
		}
		n--;
	}
	return (output);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			n;
	char		*output;

	i = 0;
	output = NULL;
	n = get_modn(format);
	va_start(ap, format);
	if (!(output = get_output(format, ap, n)))
		return (0);
	va_end(ap);
	ft_putstr(output);
	free(output);
	return (1);
}
