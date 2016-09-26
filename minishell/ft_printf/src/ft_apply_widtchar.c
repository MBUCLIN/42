/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_widtchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:19:37 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/15 13:33:26 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_printf		*joinwidthleft(t_printf *conv, char *width, int size)
{
	char	*join;
	int		dsize;

	join = NULL;
	dsize = conv->size + size;
	if (!(join = (char *)malloc(sizeof(char) * (dsize + 1))))
		return (NULL);
	ft_memcpy(join, width, size);
	ft_memcpy((join + size), conv->opt, conv->size);
	join[dsize] = 0;
	free(conv->opt);
	conv->opt = NULL;
	if (!(conv->opt = ft_strdupprintf(join, dsize)))
		return (NULL);
	free(join);
	free(width);
	conv->size = dsize;
	return (conv);
}

t_printf			*ft_apply_widtchar(char *info, t_printf *conv, int adj)
{
	int		size;
	char	*width;

	width = NULL;
	size = ft_getwidth(info) - conv->size;
	if (size >= 1)
		if (!(width = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
	if (!width)
		return (conv);
	width[size] = '\0';
	ft_memsetp(width, ' ', size);
	if (adj == 'r')
		return (ft_strjoinprintf(conv, width, size));
	return (joinwidthleft(conv, width, size));
}
