/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:23:14 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/27 16:25:42 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

int		find_command(t_shell **shell, char *command)
{
	char		*name;
	int			f;

	if ((name = get_commandname(command)) == NULL)
		return (-1);
	if ((f = search_envpath(name, shell)) == 0)
		return (0);
	else if (f == -1)
	{
		free(name);
		return (-1);
	}
	return (search_cpath(shell, name, (*shell)->path->cpath));
}
