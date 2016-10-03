/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:32:20 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/01 14:13:38 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

static char		**new_arg(char ***arg, char *new)
{
	if (new == NULL)
		return (NULL);
	else if (new[0] == 0)
	{
		free(new);
		return (*arg);
	}
	if ((*arg = ft_addstrtotab(*arg, new)) == NULL)
		return (NULL);
	free(new);
	return (*arg);
}

static void		check_q(int (*quote)[2], char *command)
{
	if (command[0] == 34)
		(*quote)[0]++;
	else if (command[0] == 39)
		(*quote)[1]++;
}

char			**get_arguments(char *command, char ***arg)
{
	int		q[2];
	int		i;
	int		s;

	i = ft_skpblk(command);
	q[0] = 0;
	q[1] = 0;
	s = i;
	while (command[i])
	{
		check_q(&q, command + i);
		if ((q[0] == 0 || q[0] % 2 == 0) && (q[1] == 0 || q[1] % 2 == 0) &&\
			ft_isblank(command[i]))
		{
			s += ft_skpblk(command + s);
			if ((*arg = new_arg(arg, ft_strsub(command, s, i - s))) == NULL)
				return (NULL);
			i += ft_skpblk((command + i)) - 1;
			s = i + 1;
		}
		i++;
	}
	s += ft_skpblk(command + s);
	return (new_arg(arg, ft_strsub(command, s, i - s)));
}

char			*get_var(char *arg, char **env)
{
	char		*var;
	char		*ret;

	if ((var = ft_strjoin(arg, "=")) == NULL)
		end_minishell(-1);
	if ((ret = ft_srchenv(var, env)) == NULL)
	{
		free(var);
		return (NULL);
	}
	if ((ret = ft_strjoinfree(var, ret)) == NULL)
		end_minishell(-1);
	return (ret);
}

char			*cut_envvar(char *var)
{
	int		i;

	i = 0;
	while (var[i])
	{
		if (var[i] == '=')
			return (ft_strsub(var, 0, i));
		i++;
	}
	return (NULL);
}
