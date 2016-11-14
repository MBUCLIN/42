/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:12:29 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/14 11:13:31 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void		del_command(t_command *cmd)
{
	if (cmd)
	{
		free(cmd->command);
		free(cmd->szchar);
		free(cmd->prompt);
		free(cmd);
	}
}
