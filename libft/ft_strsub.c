/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:57:47 by mbuclin           #+#    #+#             */
/*   Updated: 2015/12/15 14:29:35 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*toret;
	int		i;
	int		j;

	i = 0;
	j = start;
	if (!(toret = (char *)ft_memalloc(sizeof(char) * len + 1)) || s == NULL)
		return (NULL);
	while ((char *)(s + j) <= (char *)(s + start + len - 1))
	{
		toret[i] = s[j];
		i++;
		j++;
	}
	return (toret);
}
