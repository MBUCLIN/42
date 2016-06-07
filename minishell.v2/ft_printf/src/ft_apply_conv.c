/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:20:48 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/16 14:38:06 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_printf		*cpy_conv(char *arg, int len)
{
	int			i;
	t_printf	*conv;

	if (!(conv = (t_printf *)malloc(sizeof(t_printf) * 1)))
		return (NULL);
	if (len >= 0)
	{
		if (!(conv->opt = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		conv->opt[len] = '\0';
	}
	i = -1;
	while (++i < len)
		conv->opt[i] = *(arg + i);
	conv->size = len;
	return (conv);
}

static t_printf		*preciislessthansize(t_printf *conv, int size)
{
	if (!(conv->opt = ft_strsubfree(conv->opt, 0, size)))
		return (NULL);
	conv->size = size;
	return (conv);
}

static t_printf		*get_convs(int adj, t_printf *conv, char *info)
{
	int		size;

	size = ft_getpreci(info);
	if (size != -1 && size < conv->size)
		if (!(conv = preciislessthansize(conv, size)))
			return (NULL);
	return (ft_apply_widtchar(info, conv, adj));
}

static t_printf		*apply_convs(char *info, int adj, va_list ap)
{
	int			len;
	char		*s;
	t_printf	*conv;

	s = NULL;
	conv = NULL;
	s = va_arg(ap, char *);
	if (s == NULL)
	{
		if (!(conv = (t_printf *)malloc(sizeof(t_printf) * 1)))
			return (NULL);
		if (!(conv->opt = ft_strdupp("(null)")))
			return (NULL);
		conv->size = 6;
		return (get_convs(adj, conv, info));
	}
	len = ft_strlenp(s);
	if (!(conv = cpy_conv(s, len)))
		return (NULL);
	return (get_convs(adj, conv, info));
}

t_printf			*ft_apply_conv(char *info, int lm, va_list ap)
{
	int		c;
	int		adj;

	adj = ft_getadj(info);
	c = info[ft_strlenp(info) - 1];
	if ((c == 'c' && lm != 'l') || c == '%')
		return (ft_apply_charc(info, adj, ap));
	else if (c == 's' && lm != 'l')
		return (apply_convs(info, adj, ap));
	else if (c == 'p' || c == 'P')
		return (ft_apply_convp(info, adj, ap));
	else if (c == 'C' || c == 'c')
		return (ft_apply_wint(info, adj, ap));
	return (ft_apply_wchar(info, adj, ap));
}
