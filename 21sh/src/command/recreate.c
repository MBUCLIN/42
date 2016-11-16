/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 14:33:21 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/15 15:59:13 by mbuclin          ###   ########.fr       */
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

void			recreate(t_command **cmd, int len)
{
	while (((*cmd)->len + len) > (*cmd)->alloc)
	{
		(*cmd)->command = recreate_command((*cmd)->command, (*cmd)->alloc);
		(*cmd)->szchar = recreate_szchar((*cmd)->szchar, (*cmd)->alloc);
		(*cmd)->alloc += BUF_SIZE;
		if ((*cmd)->command == NULL || (*cmd)->szchar == NULL)
		{
			sherror("21sh", ERRMALLOC, NULL);
			exit(-1);
		}
	}
}
