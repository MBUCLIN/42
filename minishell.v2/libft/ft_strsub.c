/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:57:47 by mbuclin           #+#    #+#             */
/*   Updated: 2016/07/12 14:18:33 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*toret;
	size_t		i;
	size_t		j;

	i = 0;
	j = start;
	if (!(toret = (char *)ft_memalloc(sizeof(char) * len + 1)) || s == NULL)
		return (NULL);
	while (i < len && s[j])
	{
		toret[i] = s[j];
		i++;
		j++;
	}
	return (toret);
}
