/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_charc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:22:48 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/15 15:13:58 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_printf			*ft_apply_charc(char *info, int adj, va_list ap)
{
	char		c;
	t_printf	*conv;

	if (!(conv = (t_printf *)malloc(sizeof(t_printf) * 1)))
		return (NULL);
	if (info[ft_strlen(info) - 1] != '%')
	{
		c = (char)va_arg(ap, int);
		if (!(conv->opt = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		conv->opt[0] = c;
		conv->opt[1] = 0;
	}
	else
	{
		if (!(conv->opt = ft_strdup("%")))
			return (NULL);
	}
	conv->size = 1;
	return (ft_apply_widtchar(info, conv, adj));
}
