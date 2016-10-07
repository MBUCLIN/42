/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisblank.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:14:18 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/01 14:17:18 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strisblank(char *str)
{
	int		i;
	int		blank;

	blank = ft_strlen(str);
	i = 0;
	if (str == NULL || blank == 0)
		return (1);
	while (str[i])
	{
		if (ft_isblank(str[i]))
			blank--;
		i++;
	}
	if (blank == 0)
		return (1);
	return (0);
}
