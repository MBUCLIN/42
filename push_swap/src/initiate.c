/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 13:08:58 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 17:43:48 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		set_option(char *option, int car)
{
	if (car == 'n')
		option[NUMBER] = 1;
	else if (car == 'c')
		option[COLOR] = 1;
	else if (car == 's')
		option[STATE] = 1;
}

char			*init_option(char **args)
{
	char	*option;
	int		i;
	int		j;

	option = NULL;
	if (!(option = (char *)malloc(sizeof(char) * (NB_OPTION + 1))))
		return (NULL);
	ft_memset(option, 0, NB_OPTION + 1);
	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			set_option(option, args[i][j]);
			j++;
		}
		i++;
	}
	return (option);
}

t_pile			*init_tmp_and_pos(t_pile **head, int size)
{
	ssize_t		ret;
	int			i;
	int			pos;
	t_pile		*tmp;

	ret = -2147483649;
	i = 1;
	pos = 1;
	tmp = *head;
	while (tmp)
	{
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
	while (i <= size)
	{
		tmp = get_lowernode(*head, ret);
		tmp->tmp = i;
		ret = tmp->num;
		i++;
	}
	return (*head);
}

static void		set_component(t_turn **head)
{
	(*head)->a = NULL;
	(*head)->b = NULL;
	(*head)->info = NULL;
	(*head)->moov = NULL;
	(*head)->command = NULL;
}

t_turn			*init_turn(char **args)
{
	t_turn		*start;
	int			n_option;
	t_pile		*tmp;

	n_option = after_option(args);
	start = NULL;
	if (!(start = (t_turn *)malloc(sizeof(t_turn))))
		return (NULL);
	set_component(&start);
	if (!(tmp = (t_pile *)malloc(sizeof(t_pile))))
		return (del_turn(start));
	start->a = tmp;
	while (args[n_option])
	{
		tmp->num = ft_atoi(args[n_option]);
		n_option++;
		tmp->next = NULL;
		if (args[n_option])
			if (!(tmp->next = (t_pile *)malloc(sizeof(t_pile))))
				return (del_turn(start));
		tmp = tmp->next;
	}
	return (start);
}
