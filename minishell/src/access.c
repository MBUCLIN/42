/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 19:45:31 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/01 14:31:44 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int		fill_access(char (*access)[256], char *path, char *xname)
{
	int		i;
	int		j;

	i = 0;
	if (path)
		while (path[i])
		{
			(*access)[i] = path[i];
			i++;
		}
	j = 0;
	(*access)[i++] = '/';
	while (xname[j])
	{
		(*access)[i] = xname[j];
		j++;
		i++;
	}
	(*access)[i] = 0;
	return (i);
}
