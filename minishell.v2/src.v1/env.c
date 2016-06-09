/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 14:13:29 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/09 17:01:30 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

char		**rem_env(char **env, char **arg)
{
	char		*var;
	int			len;
	int			i;

	i = 1;
	len = ft_tabstrlen(env);
	while (arg[i])
	{
		if ((var = get_var(arg[i], env)) == NULL)
		{
			ft_perror("unsetenv: illegal name -- ", ft_strdup(arg[i]));
			ft_putendl_fd(2, "usage: unsetenv [NAME ...]");
			return (env);
		}
		env = ft_deltabswapstr(env, var, len--);
		free(var);
		var = NULL;
		i++;
	}
	return (env);
}

static char		**arg_exist(char **env, char **arg)
{
	int		i;
	char	**new;

	i = 0;
	while (arg[++i])
		if (ft_strchr(arg[i], '$'))
		{
			if ((new = ft_strsplit(arg[i], '=')) == NULL)
				end_minishell(-1);
			if ((new = change_args(new, env)) == NULL)
				end_minishell(-1);
			if ((new[0] = ft_strjoinfree(new[0], "=")) == NULL)
				end_minishell(-1);
			rem_env(env, &new[0]);
			free(arg[i]);
			if ((arg[i] = ft_strjoindfree(new[0], new[1])) == NULL)
				end_minishell(-1);
			free(new);
			new = NULL;
		}
		else if (ft_srchenv(arg[i], env))
			env = rem_env(env, arg);
	return (env);
}

char		**add_env(char **env, char **arg)
{
	char	*bad;
	int		i;

	if ((bad = bad_arg(arg)))
	{
		ft_perror("setenv: illegal name or value -- ", ft_strdup(bad));
		ft_putendl_fd(2, "usage: setenv [NAME=value ...]");
		return (env);
	}
	env = arg_exist(env, arg);
	i = 0;
	while (arg[++i])
	{
		if (ft_strchr(arg[i], '$'))
		{

		}
		else if ((env = ft_addstrtotab(env, arg[i])) == NULL)
			return (NULL);
		ft_printf("setenv: %s\n", arg[i]);
	}
	ft_puttab(env);
	return (env);
}
