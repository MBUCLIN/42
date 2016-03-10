/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_convp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:08:20 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/10 16:06:36 by mbuclin          ###   ########.fr       */
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
	conv->size = ft_strlen(conv->opt);
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
	ft_memset(width, c, size);
	return (get_convetwidth(conv, width, adj));
}

static t_printf		*get_p(int adj, char *info, t_printf *conv)
{
	char		*preci;
	int			size;

	preci = NULL;
	size = ft_getpreci(info) - conv->size;
	if (!(conv->opt = ft_strjoindfree(ft_strdup("0x"), conv->opt)))
		return (NULL);
	if (size > 1)
		if (!(preci = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
	if (!preci)
		return (apply_widthp(adj, info, conv));
	preci[size] = '\0';
	ft_memset(preci, '0', size);
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

	if (!(conv = (t_printf *)malloc(sizeof(t_printf) * 1)))
		return (NULL);
	p = va_arg(ap, void *);
	adr = (unsigned long)p;
	if (!(conv->opt = ft_sitoabase(adr, "0123456789abcdef")))
		return (NULL);
	conv->size = ft_strlen(conv->opt);
	return (get_p(adj, info, conv));
}
