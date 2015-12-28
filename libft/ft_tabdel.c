/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:45:40 by mbuclin           #+#    #+#             */
/*   Updated: 2015/12/17 17:13:05 by lgosse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(void **todel)
{
	size_t		i;

	i = -1;
	if (todel)
	{
		while ((unsigned char *)todel[++i])
		{
			free(todel[i]);
			todel[i] = NULL;
		}
		free(todel);
		todel = NULL;
	}
}
