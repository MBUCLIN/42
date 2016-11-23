/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:46:06 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/23 13:40:27 by mbuclin          ###   ########.fr       */
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
	{
		free(saved);
		saved = NULL;
	}
	else if (command[0] == -1)
	{
		free(command);
		return (saved);
	}
	else
		saved = ft_strdup(command);
	return (saved);
}

static int		check_index(int index, t_list *hist)
{
	if (hist == NULL || index < 0 || index > ft_lstlen(hist))
		return (0);
	return (1);
}

void			handle_history(int way, t_command **cmd)
{
	t_list			*hist;
	static int		index = 0;

	hist = save_history(NULL);
	if (way == 0)
	{
		index = 0;
		return ;
	}
	if (check_index(index + way, hist) == 0)
		return ;
	else if (index == 0)
		save_command((*cmd)->command);
	get_index(hist, index, way);
	moove_start(get_cursor(LOCAT, cmd), 0);
	ft_termstr("cd");
	ft_putlst(hist);
	free((*cmd)->command);
	free((*cmd)->szchar);
	(*cmd)->command = NULL;
	(*cmd)->szchar = NULL;
}
