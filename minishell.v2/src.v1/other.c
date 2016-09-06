/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 19:45:31 by mbuclin           #+#    #+#             */
/*   Updated: 2016/09/06 15:16:18 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int			fill_access(char (*access)[256], char *path, char *xname)
{
	int		i;
	int		j;

	i = 0;
	if (path)
		while (path[i] && i < 256)
		{
			(*access)[i] = path[i];
			i++;
		}
	j = 0;
	if (i)
		(*access)[i++] = '/';
	while (xname[j] && i < 256)
	{
		(*access)[i] = xname[j];
		j++;
		i++;
	}
	(*access)[i] = 0;
	if (i == 256 && xname[j] != 0)
		return (-1);
	return (i);
}

char		**env_alloc(int len)
{
	char		**env;

	env = NULL;
	if (!len)
		return (env);
	if ((env = (char **)malloc(sizeof(char *) * (len + 1))) == NULL)
		end_minishell(-1);
	env[len] = NULL;
	return (env);
}
