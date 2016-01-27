/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:18:10 by mbuclin           #+#    #+#             */
/*   Updated: 2015/12/15 13:25:16 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	len;
	size_t	i;

	i = -1;
	len = 0;
	while (s2[++i])
		len++;
	i = 0;
	while (s1[i])
		i++;
	if (i < len)
		return (NULL);
	if (len == 0 && s2 != NULL)
		return ((char *)s1);
	i = 0;
	while (s1[i + len - 1])
	{
		if ((ft_memcmp((char *)(s1 + i), s2, len) == 0))
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
