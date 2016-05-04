/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islexisort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:34:47 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/04 16:47:10 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_islexisort(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2)
	{
		if (s1[i] < s2[i])
			return (0);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	if (ft_strlen(s1) < ft_strlen(s2))
		return (0);
	return (1);
}
