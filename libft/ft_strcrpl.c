/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcrpl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:52:54 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/21 14:56:55 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strcrpl(char *str, int search, int replace)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == search)
			str[i] = replace;
		i++;
	}
	return (str);
}
