/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 14:25:01 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/09 17:50:36 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

void			ft_perror(char *msg, char *more)
{
	char		print[256];

	if (more)
	{
		ft_strcpy(print, msg);
		ft_strcpy((print + ft_strlen(msg)), more);
		print[ft_strlen(msg) + ft_strlen(more)] = 0;
		ft_putendl_fd(2, print);
		free(more);
	}
	else
		ft_putendl_fd(2, msg);
}

void			end_minishell(int exitval)
{
	if (exitval == -1)
		ft_perror("minishell: malloc error", NULL);
	exit(exitval);
}

void			errorformat(char *err)
{
	ft_putstr_fd("env: ", 2);
	ft_putstr_fd(err, 2);
	ft_putendl_fd(2, ": bad format: [NAME=value ...]");
}

char			*bad_arg(char **arg)
{
	int		i;

	i = 1;
	while (arg[i])
	{
		if (ft_strchr(arg[i], '=') == NULL)
			return (arg[i]);
		i++;
	}
	return (NULL);
}

void			msg_signal(int sig, char *xname)
{
	char		*name;

	if ((name = ft_strdup(xname)) == NULL)
		end_minishell(-1);
	if (sig == 11)
		ft_perror("minishell: segmentation fault: ", name);
	else if (sig == 6)
		ft_perror("minishell: abort: ", name);
	else if (sig == 10)
		ft_perror("minishell: bus error: ", name);
	else if (sig == 8)
		ft_perror("minishell: floating point execption: ", name);
	free(name);
}
