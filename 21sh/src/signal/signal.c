/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:53:53 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/04 17:39:49 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void			ft_signalerror(char *sh, char *msg, char *name)
{
	ft_putstr_fd(sh, 2);
	ft_putstr_fd(msg, 2);
	ft_putendl_fd(2, name);
}

static void			handle_message(int sig, int pid, char *name)
{
	int		i;
	int		*check;
	char	**msg;

	i = 0;
	check = get_checker();
	msg = get_message();
	while (i < MSGSIGSZE)
	{
		if (check[i] == sig)
		{
			kill(pid, sig);
			ft_signalerror("21sh:	", msg[i], name);
		}
		i++;
	}
}

static void		handle_specialsignal(int sig)
{
	if (sig == 2)
		signal(sig, ft_prompt);
	else if (sig == 28)
		signal(sig, win_resized);
}

void			ft_changesignal(int sig, int pid, char *name)
{
	int		i;
	int		def;

	i = 1;
	if (name)
		while (i < 32)
		{
			signal(sig, SIG_DFL);
			if (is_message(i) == 1 && i == sig)
				handle_message(i, pid, name);
			i++;
		}
	if (name == NULL)
		while (i < 32)
		{
			if ((def = is_dori(i)) == 1)
				signal(i, SIG_DFL);
			else if (def == -1)
				signal(i, SIG_IGN);
			else if (is_message(i) == 1)
				signal(i, SIG_DFL);
			else if (is_other(i) == 1)
				handle_specialsignal(i);
			i++;
		}
}
