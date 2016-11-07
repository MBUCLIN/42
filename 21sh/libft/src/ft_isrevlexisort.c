/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isrevlexisort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:21:10 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/09 14:24:10 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_isrevlexisort(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] > s2[i])
			return (0);
		else if (s1[i] < s2[i])
			return (1);
		i++;
	}
	if (ft_strlen(s1) > ft_strlen(s2))
		return (0);
	return (1);
}
