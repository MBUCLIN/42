/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_convp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:08:20 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/17 13:44:44 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_printf		*get_convetwidth(t_printf *conv, char *width, int adj)
{
	int		n;

	n = 0;
	if (width[0] == '0')
		n = 2;
	else if (adj == 'r')
		n = conv->size;
	if (!(conv->opt = ft_strmidadd(conv->opt, width, n)))
		return (NULL);
	conv->size = ft_strlenp(conv->opt);
	return (conv);
}

static t_printf		*apply_widthp(int adj, char *info, t_printf *conv)
{
	char		*width;
	int			size;
	char		c;

	c = ' ';
	width = NULL;
	size = ft_getwidth(info) - conv->size;
	if (size > 0)
		if (!(width = (char *)malloc(sizeof(char) * size + 1)))
			return (0);
	if (!width)
		return (conv);
	width[size] = '\0';
	if (ft_getpreci(info) == -1 && adj == 'l')
		c = '0';
	ft_memsetp(width, c, size);
	return (get_convetwidth(conv, width, adj));
}

static t_printf		*get_p(int adj, char *info, t_printf *conv)
{
	char		*preci;
	int			size;

	preci = NULL;
	size = ft_getpreci(info) - conv->size;
	if (!(conv->opt = ft_strjoindfree(ft_strdupp("0x"), conv->opt)))
		return (NULL);
	conv->size = ft_strlenp(conv->opt);
	if (size > 1)
		if (!(preci = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
	if (!preci)
		return (apply_widthp(adj, info, conv));
	preci[size] = '\0';
	ft_memsetp(preci, '0', size);
	if (!(conv->opt = ft_strmidadd(conv->opt, preci, 2)))
		return (NULL);
	conv->size += size;
	return (apply_widthp(adj, info, conv));
}

t_printf			*ft_apply_convp(char *info, int adj, va_list ap)
{
	long		adr;
	void		*p;
	t_printf	*conv;
	int			preci;

	if (!(conv = (t_printf *)malloc(sizeof(t_printf) * 1)))
		return (NULL);
	p = va_arg(ap, void *);
	adr = (unsigned long)p;
	preci = ft_getpreci(info);
	if (adr == 0 && preci == 0)
	{
		if (!(conv->opt = ft_strdupp("0x")))
			return (NULL);
		conv->size = 2;
		return (apply_widthp(adj, info, conv));
	}
	if (!(conv->opt = ft_sitoabasep(adr, "0123456789abcdef")))
		return (NULL);
	conv->size = ft_strlenp(conv->opt);
	return (get_p(adj, info, conv));
}
