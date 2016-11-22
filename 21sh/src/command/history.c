/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:46:06 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/22 17:07:15 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void			ft_putlst(t_list *lst)
{
	t_list		*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_putendl(tmp->content);
		tmp = tmp->next;
	}
}

t_list			*save_history(char *command)
{
	static t_list		*history = NULL;
	t_list				*tmp;
	char				*content;
	int					len;

	tmp = NULL;
	len = ft_strlen(command);
	if (len && !ft_strisblank(command))
	{
		if ((content = ft_strsub(command, 0, len - 1)) == NULL)
			ft_exitshell("21sh", ERRMALLOC, NULL);
		if ((tmp = ft_lstnew(content, len)) == NULL)
			ft_exitshell("21sh", ERRMALLOC, NULL);
		tmp->next = history;
		history = tmp;
		free(content);
	}
	return (history);
}

static t_list	*get_index(t_list *hist, int i, int way)
{
	t_list		*tmp;
	int			count;
	int			len;

	tmp = hist;
	count = 1;
	len = ft_lstlen(hist);
	if ((i + way) == 0 || (i + way) == -1)
		return (NULL);
	while (tmp)
	{
		if ((i + way) == count || count == len)
		{
			ft_printf("%d : i + way\n", i + way);
			break ;
		}
		count++;
		tmp = tmp->next;
	}
	return (tmp);
}

static char		*save_command(char *command)
{
	static char		*saved = NULL;

	if (command == NULL)
		return (saved);
	else
		saved = ft_strdup(command);
	return (saved);
}

void			handle_history(char *buf, t_command **cmd)
{
	t_list			*hist;
	static int		index = 0;
	t_list			*tmp;
	int				len;

	if (index == 0)
		save_command((*cmd)->command);
	moove_start(get_cursor(LOCAT, cmd), 0);
	ft_termstr("cd");
	hist = save_history(NULL);
	if (hist == NULL)
		return ;
	ft_putlst(hist);
	free((*cmd)->command);
	free((*cmd)->szchar);
	(*cmd)->szchar = NULL;
	sleep(2);
	if ((tmp = get_index(hist, index, buf[2] == 65 ? 1 : -1)) == NULL)
		(*cmd)->command = save_command(NULL);
	else
		(*cmd)->command = ft_strdup(tmp->content);
	len = ft_strlen((*cmd)->command);
	(*cmd)->len = len;
	(*cmd)->alloc = len;
	index += buf[2] == 65 ? 1 : -1;
	ft_putstr((*cmd)->prompt);
	ft_putstr((*cmd)->command);
}
