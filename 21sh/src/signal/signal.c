/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:53:53 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/03 16:28:32 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void			handleself(int sig)
{
	if (sig == 2)
	{
		signal(sig, ft_prompt);
	}
	else
		handle_resize();
}

void			ft_changesignal(int sig, void (*func)(int))
{
	int		i;

	if (sig)
	{
		signal(sig, func);
		return ;
	}
	i = 1;
	while (i < NSIG)
	{
		if (is_dori(i) == -1)
			signal(i, SIG_IGN);
		else if (is_dori(i) == 1)
			signal(i, SIG_DFL);
		else if (is_other(i))
			handleself(i);
		else
			handle_message(i);
		i++;
	}
}
