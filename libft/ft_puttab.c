/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:07:59 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/06 15:09:55 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_puttab(char **tab)
{
	int		i;

	i = 0;
	if (tab)
		while (tab[i])
		{
			if (!tab[i])
				return ;
			ft_putendl(tab[i]);
			i++;
		}
}
