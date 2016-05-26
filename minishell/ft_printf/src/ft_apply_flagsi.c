/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flagsi.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:22:24 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/17 15:47:22 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*apply_unsignedflags(int c, char *info, char *conv)
{
	int		i;

	i = 0;
	while (info[i])
	{
		if (info[i] == '#')
		{
			if (c == 'x' && conv[0] != '0' && conv[0] != 0)
				return (ft_strdupp("0x"));
			else if (c == 'X' && conv[0] != '0' && conv[0] != 0)
				return (ft_strdupp("0X"));
			else if ((c == 'o' || c == 'O') && conv[0] != '0')
				return (ft_strdupp("0"));
		}
		i++;
	}
	return (NULL);
}

static char		*apply_signedflags(char *info, char *conv)
{
	int		i;
	int		space;

	space = 0;
	i = 0;
	while (info[i])
	{
		if (info[i] == '+' && conv[0] != '-')
			return (ft_strdupp("+"));
		else if (info[i] == ' ' && conv[0] != '-')
			space = 1;
		i++;
	}
	if (space == 1)
		return (ft_strdupp(" "));
	return (NULL);
}

static char		*apply_flags(char *info, char *conv)
{
	int		c;
	char	*flag;

	flag = NULL;
	c = info[ft_strlenp(info) - 1];
	if (ft_isunsigned(c))
	{
		if (!(flag = apply_unsignedflags(c, info, conv)))
			return (NULL);
	}
	else
	{
		if (!(flag = apply_signedflags(info, conv)))
			return (NULL);
	}
	return (flag);
}

t_printf		*ft_apply_flagsi(char *info, t_printf *conv)
{
	int		adj;
	char	*flags;

	flags = apply_flags(info, conv->opt);
	if (!(conv->opt = ft_strjoindfree(flags, conv->opt)))
		return (NULL);
	conv->size = ft_strlenp(conv->opt);
	adj = ft_getadj(info);
	if (!(conv->opt = ft_apply_pandw(adj, info, conv->opt)))
		return (NULL);
	conv->size = ft_strlenp(conv->opt);
	return (conv);
}
