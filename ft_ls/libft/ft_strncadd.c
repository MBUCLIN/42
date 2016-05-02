/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:03:25 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/02 17:57:36 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strncadd(char *str, int n, int c)
{
	char		*add;
	int			i;

	add = NULL;
	i = 0;
	if (!(add = (char *)malloc(sizeof(char) * (n + 1))))
	{
		free(str);
		return (NULL);
	}
	while (i < n)
	{
		add[i] = c;
		i++;
	}
	add[i] = 0;
	return (ft_strjoindfree(str, add));
}
