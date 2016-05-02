/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 15:18:31 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 14:33:37 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_cmd		*create_node_command(int action)
{
	t_cmd		*node;

	if (!(node = malloc(sizeof(t_cmd))))
		return (NULL);
	node->next = NULL;
	node->turn = 1;
	if (!(node->command = get_command(action)))
	{
		free(node);
		return (NULL);
	}
	return (node);
}

t_cmd		*fill_list_command(t_cmd **cmd, int action)
{
	t_cmd		*newnode;
	t_cmd		*tmp;

	if (!(newnode = create_node_command(action)))
	{
		del_command(*cmd);
		return (NULL);
	}
	if (!*cmd)
		return (newnode);
	tmp = last_cmd(*cmd);
	tmp->next = newnode;
	newnode->turn += tmp->turn;
	return (*cmd);
}
