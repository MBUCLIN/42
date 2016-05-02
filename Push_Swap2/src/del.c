/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 13:10:35 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/21 16:19:06 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_del_tab(ssize_t *tab, int ret)
{
	free(tab);
	tab = NULL;
	return (ret);
}

void	del_pile(t_pile *head)
{
	t_pile	*tmp;

	if (head)
		tmp = head->next;
	while (head)
	{
		free(head);
		head = NULL;
		head = tmp;
		if (tmp)
			tmp = tmp->next;
	}
}

t_turn	*del_turn(t_turn *head)
{
	del_pile(head->a);
	head->a = NULL;
	del_pile(head->b);
	head->b = NULL;
	free(head);
	return (NULL);
}

t_cmd	*del_command(t_cmd *cmd)
{
	t_cmd		*tmp;

	if (cmd)
		tmp = cmd->next;
	while (cmd)
	{
		free(cmd->command);
		free(cmd);
		cmd = NULL;
		cmd = tmp;
		if (tmp)
			tmp = tmp->next;
	}
	return (NULL);
}
