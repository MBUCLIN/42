/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:41:14 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/22 17:42:14 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		print_pile_a(t_turn *node, int color, int ncmd)
{
	t_pile	*tmp;

	tmp = node->a;
	if (color)
		ft_putstr("\033[32mPile A :\033[0m");
	else
		ft_putstr("Pile A :");
	while (tmp)
	{
		if (color && (ncmd == RA || ncmd == RR) && !tmp->next)
			ft_printf("\033[32m %d\033[0m", tmp->num);
		else if (color && (ncmd == RRA || ncmd == SA || ncmd == PA ||\
				ncmd == SS || ncmd == RRR) && tmp == node->a)
			ft_printf("\033[32m %d\033[0m", tmp->num);
		else if (color && (ncmd == SA || ncmd == SS) && tmp == node->a->next)
			ft_printf("\033[32m %d\033[0m", tmp->num);
		else
			ft_printf(" %d", tmp->num);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void		print_pile_b(t_turn *node, int color, int ncmd)
{
	t_pile	*tmp;

	tmp = node->b;
	if (color)
		ft_putstr("\033[32mPile B :\033[0m");
	else
		ft_putstr("Pile B :");
	while (tmp)
	{
		if (color && (ncmd == RB || ncmd == RR) && !tmp->next)
			ft_printf("\033[32m %d\033[0m", tmp->num);
		else if (color && (ncmd == RRB || ncmd == SB || ncmd == PB ||\
				ncmd == SS || ncmd == RRR) && tmp == node->b)
			ft_printf("\033[32m %d\033[0m", tmp->num);
		else if (color && (ncmd == SB || ncmd == SS) && tmp == node->b->next)
			ft_printf("\033[32m %d\033[0m", tmp->num);
		else
			ft_printf(" %d", tmp->num);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void		put_piles(t_turn *node, const char *option, int cmd)
{
	print_pile_a(node, option[COLOR], cmd);
	print_pile_b(node, option[COLOR], cmd);
}

void		put_command(t_cmd *command, int n)
{
	t_cmd		*tmp;
	int			i;

	tmp = command;
	i = 0;
	while (tmp)
	{
		ft_printf("%s = %d turn\n", tmp->command, tmp->turn);
		i++;
		tmp = tmp->next;
	}
	if (n)
		ft_printf("It took %d turn(s) to sort it\n", i);
}
