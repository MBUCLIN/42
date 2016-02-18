/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:55:22 by mbuclin           #+#    #+#             */
/*   Updated: 2016/02/18 17:05:07 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		string_len(char *s)
{
	int		i;

	i = 0;
	while (*(s + i) != 0)
		i++;
	return (i);
}

static char		*get_s(char *s, int len)
{
	char	*ret;
	int		i;

	ret = NULL;
	if (!(ret = (char *)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	i = -1;
	while (++i < len)
		ret[i] = *(s + i);
	return (ret);
}

static char		*get_convs(int sizew, int sizep, int adj, char *s)
{
	char	*preci;
	char	*width;
	int		len;

	len = ft_strlen(s);
	width = NULL;
	if (sizep > len && len != 0)
		if (!(preci = (char *)ft_memalloc(sizeof(char) * (sizep - len))))
			return (NULL);
	if (sizep > len && len != 0)
		ft_memset(preci, ' ', sizep - len);
	if (len == 0 || !(s = ft_strjoindfree(preci, s)))
		return (NULL);
	if (sizew > (int)ft_strlen(s))
	{
		sizew -= ft_strlen(s);
		if (!(width = (char *)ft_memalloc(sizeof(char) * sizew)))
			return (NULL);
	}
	if (width)
		ft_memset(width, ' ', sizew);
	if (adj == 'r')
		return (ft_strjoindfree(s, width));
	return (ft_strjoindfree(width, s));
}

static char		*apply_convs(char *info, int adj, va_list ap)
{
	char	*s;
	int		width;
	int		preci;
	int		len;

	s = NULL;
	s = va_arg(ap, char *);
	preci = ft_getpreci(info);
	width = ft_getwidth(info);
	free(info);
	if (s == NULL)
		return (get_convs(5, width, preci, adj, ft_strdup("(nul)")));
	len = string_len(s);
	return (get_convs(width, preci, adj, get_s(s, len)));
}

char			*ft_apply_conv(char *info, va_list ap, int lm)
{
	int		c;
	int		adj;

	adj = ft_getadj(info);
	c = info[ft_strlen(info) - 1];
	if ((c == 'c' || c == '%') && lm != 'l')
		return (ft_apply_charc(info, adj, ap));
	else if (c == 's' && lm != 'l')
		return (apply_convs(info, adj, ap));
	else if (c == 'p' || c == 'P')
		return (ft_apply_convp(info, adj, ap));
	return (NULL);
}
