/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_pandw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:18:36 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/14 18:28:13 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*apply_preci(char *conv, int minus, int size, char *info)
{
	int		sizep;
	char	*preci;

	sizep = ft_getpreci(info);
	preci = NULL;
	if (size == 1 && sizep != -1 && conv[0] == 0 && !ft_carchr('#', info))
		return (ft_strdupp(""));
	sizep = sizep - (size - minus);
	if (sizep >= 1)
		if (!(preci = (char *)malloc(sizeof(char) * (sizep + 1))))
			return (NULL);
	if (!preci)
		return (conv);
	ft_memsetp(preci, '0', sizep);
	preci[sizep] = 0;
	return (ft_strmidadd(conv, preci, minus));
}

static char		*get_width(char *conv, char *width, int minus, int adj)
{
	if (adj == 'r')
		return (ft_strjoindfree(conv, width));
	else if (minus == 2 && width[0] == '0')
		return (ft_strmidadd(conv, width, 2));
	else if (minus == 1 && width[0] == '0')
		return (ft_strmidadd(conv, width, 1));
	return (ft_strjoindfree(width, conv));
}

static char		*apply_width(int adj, char *conv, char *info, int minus)
{
	char	*width;
	int		sizew;

	width = NULL;
	sizew = ft_getwidth(info) - ft_strlenp(conv);
	if (sizew >= 1)
		if (!(width = (char *)malloc(sizeof(char) * (sizew + 1))))
		{
			free(conv);
			return (NULL);
		}
	if (width == NULL)
		return (conv);
	width[sizew] = 0;
	if (ft_getpreci(info) == -1 && adj == 'l')
		ft_memsetp(width, '0', sizew);
	else
		ft_memsetp(width, ' ', sizew);
	return (get_width(conv, width, minus, adj));
}

char			*ft_apply_pandw(int adj, char *info, char *conv)
{
	int		minus;
	int		size;

	size = ft_strlenp(conv);
	minus = 0;
	if (conv && (conv[0] == '0' && (conv[1] == 'x' || conv[1] == 'X')))
		minus = 2;
	else if (conv && size > 1 && (conv[0] == '0' ||\
			conv[0] == ' ' || conv[0] == '+' || conv[0] == '-'))
		minus = 1;
	if (!(conv = apply_preci(conv, minus, size, info)))
		return (NULL);
	size = ft_strlenp(conv);
	return (apply_width(adj, conv, info, minus));
}
