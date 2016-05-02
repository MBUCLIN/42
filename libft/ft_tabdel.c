/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:08:57 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/06 15:10:10 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_tabdel(void **todel)
{
	size_t		i;

	i = 0;
	if (todel)
		while ((unsigned char *)todel[i])
		{
			free(todel[i]);
			todel[i] = NULL;
		}
	free(todel);
	todel = NULL;
}
