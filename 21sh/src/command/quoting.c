/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:16:44 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/24 14:06:41 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int	quoting_prompt(int q, int dq)
{
	t_command		**cmd;

	cmd = ft_getcommand();
	if (q)
		(*cmd)->qmask = QTE;
	else if (dq)
		(*cmd)->qmask = DQTE;
	set_command(cmd);
	return (-1);
}

static int	end_quoting(void)
{
	t_command		**cmd;

	cmd = ft_getcommand();
	(*cmd)->qmask = 0;
	set_command(cmd);
	return (0);
}

int			check_quotelvl(int c)
{
	static int		quote = 0;
	static int		dquote = 0;
	static char		pchar = 0;

	if (c == '\'' && quote == 0 && pchar != '\\' && dquote == 0)
		quote = 1;
	else if (c == '\'' && pchar != '\\' && quote == 1)
		quote = end_quoting();
	if (c == '"' && dquote == 0 && pchar != '\\' && quote == 0)
		dquote = 1;
	else if (c == '"' && pchar != '\\' && dquote == 1)
		dquote = end_quoting();
	if (c == '\n' && quote == 0 && dquote == 0)
		return (0);
	else if (c == '\n' && (quote == 1 || dquote == 1))
	{
		quoting_prompt(quote, dquote);
		return (-1);
	}
	pchar = c;
	return (1);
}
