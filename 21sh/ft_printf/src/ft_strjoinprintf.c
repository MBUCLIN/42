/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinprintf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:11:53 by mbuclin           #+#    #+#             */
/*   Updated: 2016/03/10 15:03:13 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			cpy_stringfree(char *dest, char *src, int lsrc)
{
	int		i;

	i = 0;
	while (i < lsrc)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	free(src);
	src = NULL;
}

t_printf			*ft_strjoinprintf(t_printf *print, char *s2, int len2)
{
	char		*join;
	int			size;

	size = print->size + len2;
	join = NULL;
	if (!(join = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	join[size] = '\0';
	if (print->opt)
		cpy_stringfree(join, print->opt, print->size);
	if (s2)
		cpy_stringfree((join + print->size), s2, len2);
	if (!(print->opt = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	print->opt[size] = 0;
	ft_memcpy(print->opt, join, size);
	print->size = size;
	free(join);
	return (print);
}
