/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 14:33:21 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/25 14:55:01 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static char		*recreate_command(char *cmd, int len)
{
	char	*newone;

	if ((newone = (char *)malloc(sizeof(char) * (len + BUF_SIZE + 1))) == NULL)
		return (NULL);
	ft_bzero(newone, len + BUF_SIZE + 1);
	newone = ft_strcpy(newone, cmd);
	free(cmd);
	return (newone);
}

static char		*recreate_szchar(char *szchar, int len)
{
	char	*newone;

	if ((newone = (char *)malloc(sizeof(char) * (len + BUF_SIZE + 1))) == NULL)
		return (NULL);
	ft_bzero(newone, len + BUF_SIZE + 1);
	newone = ft_strcpy(newone, szchar);
	free(szchar);
	return (newone);
}

void			recreate(int len)
{
	t_command		**cmd;

	cmd = ft_getcommand();
	while (((*cmd)->len + len) > (*cmd)->alloc)
	{
		(*cmd)->command = recreate_command((*cmd)->command, (*cmd)->alloc);
		(*cmd)->szchar = recreate_szchar((*cmd)->szchar, (*cmd)->alloc);
		(*cmd)->alloc += BUF_SIZE;
		if ((*cmd)->command == NULL || (*cmd)->szchar == NULL)
			ft_exitshell("21sh", ERRMALLOC, NULL);
	}
	set_command(cmd);
}

t_command		*create_command(char *prompt, int mask, char *command)
{
	t_command		*cmd;

	cmd = NULL;
	if ((cmd = (t_command *)malloc(sizeof(t_command))) == NULL)
		return (NULL);
	if ((cmd->command = (char *)malloc(sizeof(char) * (BUF_SIZE + 1))) == NULL)
		return (NULL);
	if ((cmd->szchar = (char *)malloc(sizeof(char) * (BUF_SIZE + 1))) == NULL)
		return (NULL);
	if ((cmd->prompt = ft_strdup(prompt)) == NULL)
		return (NULL);
	cmd->alloc = BUF_SIZE;
	cmd->plen = ft_strlen(prompt);
	cmd->qmask = mask;
	ft_bzero(cmd->command, BUF_SIZE + 1);
	ft_bzero(cmd->szchar, BUF_SIZE + 1);
	cmd->pos = 0;
	cmd->len = 0;
	if (ft_strlen(command) > 0)
		handle_normal(command, &cmd);
	set_command(&cmd);
	return (cmd);
}
