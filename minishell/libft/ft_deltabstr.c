/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltabstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 16:12:02 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/19 18:21:47 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_deltabstr(char **del, int pos)
{
	int		i;

	i = 0;
	while (i < pos)
	{
		if (del[i])
			free(del[i]);
		i++;
	}
	free(del);
	return (NULL);
}
