/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 16:45:54 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/26 18:01:25 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static char		*recreate_command(char *cmd)
{
	int		len;
	char	*newone;

	if (cmd != NULL)
		len = ft_strlen(cmd);
	else
		len = 0;
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

	if (szchar != NULL)
		len = ft_strlen(szchar);
	else
		len = 0;
	if ((newone = (char *)malloc(sizeof(char) * (len + BUF_SIZE + 1))) == NULL)
		return (NULL);
	ft_bzero(newone, len + BUF_SIZE + 1);
	newone = ft_strcpy(newone, szchar);
	return (newone);
}
static void		handle_end(int c, t_command **cmd)
{
	int			bt;
	int			n;

	if ((*cmd)->pos % BUF_SIZE == 0)
	{
		if (((*cmd)->command = recreate_command((*cmd)->command)) == NULL)
			exit(1);
		if (((*cmd)->szchar = recreate_szchar((*cmd)->szchar)) == NULL)
			exit(1);
	}
	(*cmd)->command[(*cmd)->pos] = c;
	bt = 1;
	n = -1;
	if (c == '\t')
	{
		bt = get_tabszst(get_cursor(LOCAT, cmd));
		c = ' ';
	}
	(*cmd)->szchar[(*cmd)->pos] = bt;
	while (++n < bt)
		write(1, &c, 1);
	(*cmd)->pos++;
	(*cmd)->len++;
}
void			handle_normal(int c, t_command **cmd)
{
	if ((*cmd)->pos == (*cmd)->len)
		handle_end(c, cmd);
}
