/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:53:02 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/02 18:02:58 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strsubfree(char *str, int n, int len)
{
	char		*dest;
	int			i;

	i = 0;
	if (!str || !len)
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
	{
		free(str);
		return (NULL);
	}
	while (i < len)
	{
		dest[i] = str[n + i];
		i++;
	}
	dest[i] = 0;
	free(str);
	return (dest);
}
