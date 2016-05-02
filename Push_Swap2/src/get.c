/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:16:35 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 18:09:27 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char		*get_command(int cmd)
{
	char		*command;

	command = NULL;
	if (!(command = (char *)malloc(sizeof(char) * 4)))
		return (NULL);
	ft_memset(command, 0, 4 + 1);
	if (cmd == RA || cmd == RB || cmd == RR || cmd == RRA ||\
		cmd == RRB || cmd == RRR)
		command[0] = 'r';
	else if (cmd == PA || cmd == PB)
		command[0] = 'p';
	else if (cmd == SA || cmd == SB || cmd == SS)
		command[0] = 's';
	if (cmd == RRA || cmd == RRB || cmd == RRR)
		command[1] = 'r';
	if (cmd <= 16)
		command[ft_strlen(command)] = 'a';
	else if (cmd > 16 && cmd < 512)
		command[ft_strlen(command)] = 'b';
	else
		command[ft_strlen(command)] = command[0];
	return (command);
}

t_pile		*get_lowernode(t_pile *head, ssize_t prev)
{
	t_pile		*tmp;
	t_pile		*tmpret;

	tmp = head;
	tmpret = head;
	while (tmpret)
	{
		if (tmpret->num > prev)
			break ;
		tmpret = tmpret->next;
	}
	while (tmp)
	{
		if (tmp->next)
			if (tmpret->num > tmp->next->num &&\
				(tmp->next->num > prev))
				tmpret = tmp->next;
		tmp = tmp->next;
	}
	return (tmpret);
}

int			get_nnode(t_turn *head, int pos, int choice)
{
	t_pile		*nodea;
	t_pile		*nodeb;

	nodea = goto_pos(head->a, pos);
	nodeb = goto_tmp(head->b, nodea->tmp - 1);
	if (choice == RR || choice == RB)
		return (nodeb->pos - 1);
	else if (choice == RRR || choice == RRB)
		return (pile_len(head->b) - nodeb->pos + 1);
	return (0);
}

int			get_pos(t_pile *stack, int num)
{
	t_pile		*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->tmp == num)
			return (tmp->pos);
		tmp = tmp->next;
	}
	return (0);
}

t_cmd		*last_cmd(t_cmd *cmd)
{
	t_cmd		*tmp;

	tmp = cmd;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
