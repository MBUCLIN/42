/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 19:45:31 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/26 19:55:50 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int		fill_access(char **access, char *path, char *xname)
{
	int		i;
	int		j;

	i = 0;
	while (path[i])
	{
		access[i] = path[i];
		i++;
	}
	j = 0;
	while (xname[j])
	{
		access[i] = path[j];
		j++;
		i++;
	}
	access[i] = 0;
	return (i);
}
