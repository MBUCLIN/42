/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltabstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:12:02 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/06 15:30:11 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_deltabstr(char **del, int pos)
{
	int		i;

	i = 0;
	if (del)
	{
		while (i < pos)
		{
			if (del[i])
			{
				free(del[i]);
				del[i] = NULL;
			}
			i++;
		}
		free(del);
	}
	return (NULL);
}
