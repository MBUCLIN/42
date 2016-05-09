/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:17:40 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/17 14:59:23 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*apply_wchar(int *wchar)
{
	char	*oct;
	int		n;
	int		i;
	int		ncar;
	char	*wconv;

	ncar = ft_get_ncar(wchar);
	wconv = NULL;
	oct = NULL;
	i = 0;
	while (ncar)
	{
		n = ft_get_nbits(*(wchar + i));
		if (!(oct = ft_getoct(*(wchar + i), ft_getmask(n))))
			return (NULL);
		n = ft_get_noct(n);
		if (!(oct = ft_convoct(oct, n)))
			return (NULL);
		if (!(wconv = ft_strjoindfree(wconv, oct)))
			return (NULL);
		i++;
		ncar--;
	}
	return (wconv);
}

static t_printf		*apply_preci(t_printf *conv, char *info)
{
	int		size;
	char	*preci;
	int		len;

	len = conv->size;
	preci = NULL;
	size = ft_getpreci(info);
	if (size > conv->size)
	{
		if (!(preci = (char *)malloc(sizeof(char) * ((size - len) + 1))))
			return (NULL);
	}
	else if (size != -1)
	{
		if (!(conv->opt = ft_strsubfree(conv->opt, 0, size)))
			return (NULL);
		conv->size = size;
	}
	if (!preci)
		return (conv);
	if (!(conv->opt = ft_strjoindfree(preci, conv->opt)))
		return (NULL);
	conv->size = ft_strlen(conv->opt);
	return (conv);
}

static t_printf		*wcharzero(t_printf *conv)
{
	if (!(conv->opt = ft_strdup("")))
		return (NULL);
	conv->size = 0;
	return (conv);
}

t_printf			*ft_apply_wchar(char *info, int adj, va_list ap)
{
	int			*wchar;
	t_printf	*conv;

	if (!(conv = (t_printf *)malloc(sizeof(t_printf) * 1)))
		return (NULL);
	wchar = va_arg(ap, int *);
	if (wchar == NULL)
	{
		if (!(conv->opt = ft_strdup("(null)")))
			return (NULL);
	}
	else if (*wchar == 0)
		return (wcharzero(conv));
	else
	{
		if (!(conv->opt = apply_wchar(wchar)))
			return (NULL);
	}
	conv->size = ft_strlen(conv->opt);
	if (!(conv = apply_preci(conv, info)))
		return (NULL);
	return (ft_apply_widtchar(info, conv, adj));
}
