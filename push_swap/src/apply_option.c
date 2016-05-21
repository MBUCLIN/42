/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 16:30:58 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/21 11:38:17 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		apply_state(t_turn *turn, char *option)
{
	t_cmd		*tmp;
	int			i;

	i = 0;
	tmp = turn->command;
	while (tmp)
	{
		if (option[COLOR])
		{
			ft_putstr("\033[32m");
			ft_putstr(tmp->command);
			ft_putendl("\033[0m");
		}
		turn = make_the_action(turn, tmp->command);
		put_piles(turn, option, reverse_process_command(tmp->command));
		tmp = tmp->next;
		i++;
	}
	if (option[NUMBER])
		ft_printf("It took %d turn(s) to sort it\n", i);
}

static void		print_command(t_cmd *command, int n)
{
	t_cmd		*tmp;
	int			i;

	tmp = command;
	i = 0;
	while (tmp)
	{
		ft_putstr("\033[32m");
		ft_putstr(tmp->command);
		ft_putstr("\033[0m");
		tmp = tmp->next;
		if (tmp)
			ft_putchar(' ');
		i++;
	}
	if (i)
		ft_putchar('\n');
	if (n)
		ft_printf("It took %d turn(s) to sort it\n", i);
}

void			print_option_and_command(t_turn *turn, char *option)
{
	if (option[STATE])
		apply_state(turn, option);
	if (option[COLOR])
		print_command(turn->command, option[NUMBER]);
	else
		put_command(turn->command, option[NUMBER]);
}
