/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recreate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 14:33:21 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/14 15:18:56 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static char		*recreate_command(char *cmd)
{
	int		len;
	char	*newone;

	len = 0;
	if (cmd != NULL)
		len = ft_strlen(cmd);
	if ((newone = (char *)malloc(sizeof(char) * (len + BUF_SIZE + 1))) == NULL)
		return (NULL);
	ft_bzero(newone, len + BUF_SIZE + 1);
	newone = ft_strcpy(newone, cmd);
	return (newone);
}

static char		*recreate_szchar(char *szchar)
{
	int		len;
	char	*newone;

	len = 0;
	if (szchar)
		len = ft_strlen(szchar);
	if ((newone = (char *)malloc(sizeof(char) * (len + BUF_SIZE + 1))) == NULL)
		return (NULL);
	ft_bzero(newone, len + BUF_SIZE + 1);
	newone = ft_strcpy(newone, szchar);
	return (newone);
}

void			recreate(t_command **cmd, int len)
{
	int		n;

	n = ((*cmd)->len + len) / BUF_SIZE - (*cmd)->len / BUF_SIZE;
	if ((*cmd)->len > 0)
		while (n)
		{
			(*cmd)->command = recreate_command((*cmd)->command);
			(*cmd)->szchar = recreate_szchar((*cmd)->szchar);
			if ((*cmd)->command == NULL || (*cmd)->szchar == NULL)
			{
				sherror("21sh", ERRMALLOC, NULL);
				exit(1);
			}
			n--;
		}
}
