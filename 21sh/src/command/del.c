/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:12:29 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/23 15:39:14 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void		del_command(t_command *cmd)
{
	if (cmd != NULL)
	{
		free(cmd->command);
		cmd->command = NULL;
		free(cmd->szchar);
		cmd->szchar = NULL;
		free(cmd->prompt);
		cmd->prompt = NULL;
		free(cmd);
		cmd = NULL;
	}
}

void		del_cmdhist(t_command *cmd)
{
	if (cmd != NULL)
	{
		if (cmd->command)
		{
			free(cmd->command);
			cmd->command = NULL;
		}
		if (cmd->szchar)
		{
			free(cmd->szchar);
			cmd->szchar = NULL;
		}
	}
}
