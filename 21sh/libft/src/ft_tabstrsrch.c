/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrsrch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 14:23:54 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/09 14:27:15 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_tabstrsrch(char *srch, char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (ft_strstr(tab[i], srch))
			return (i);
		i++;
	}
	return (i);
}
