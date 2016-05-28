/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 14:25:01 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/28 17:32:23 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

void			end_minishell(t_shell *shell)
{
	del_shell(shell);
	exit(-1);
}

void			ft_perror(char *msg, char *more)
{
	char		*print;

	print = NULL;
	if (more)
	{
		if ((print = ft_strjoin(msg, more)) == NULL)
		{
			ft_putendl_fd(2, "minishell: malloc error");
			exit(-1);
		}
		ft_putendl_fd(2, print);
		free(print);
	}
	else
		ft_putendl_fd(2, msg);
}

void		errorformat(char *err)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(err, 2);
	ft_putendl_fd(2, ": bad format: [NAME=value ...]");
}

char		*bad_arg(char **arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (check_argenv(arg[i]) == -1)
			return (arg[i]);
		i++;
	}
	return (NULL);
}

void		ft_kill(int sig)
{
	exit(sig);
}
