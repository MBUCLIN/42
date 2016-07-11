/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 14:13:29 by mbuclin           #+#    #+#             */
/*   Updated: 2016/07/11 13:50:27 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

char			**rem_env(char **env, char **arg)
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

static char		**arg_exist(char **env, char *arg)
{
	char		*new;
	char		*name;
	int			i;

	if ((name = cut_envvar(arg)) == NULL)
		end_minishell(-1);
	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], name))
		{
			if ((new = ft_strdup(arg)) == NULL)
				end_minishell(-1);
			free(env[i]);
			env[i] = new;
			free(name);
			return (env);
		}
		i++;
	}
	free(name);
	return (env);
}

char			**add_env(char **env, char **arg)
{
	char	*bad;
	int		i;

	if ((bad = bad_arg(arg)))
	{
		ft_perror("setenv: illegal name or value -- ", ft_strdup(bad));
		ft_putendl_fd(2, "usage: setenv [NAME=value ...]");
		return (env);
	}
	i = 0;
	while (arg[++i])
		if (arg[i][0] == '$')
		{
			ft_perror("env: illegal char on: ", ft_strdup(arg[i]));
			return (env);
		}
		else if (env_to_change(env, arg[i]))
			env = arg_exist(env, arg[i]);
	 	else if ((env = ft_addstrtotab(env, arg[i])) == NULL)
			return (NULL);
	ft_puttab(env);
	return (env);
}

static char		**env_opt_i(t_shell *sh, char **arg)
{
	t_exec		*tmp;
	char		**envtmp;

	tmp = sh->exec;
	sh->exec = find_commandtype(sh, arg[2]);
	if (sh->exec->xname == NULL)
	{
		del_exec(sh->exec);
		sh->exec = tmp;
		return (sh->env);
	}
	envtmp = sh->env;
	sh->env = NULL;
	exec_command(sh);
	del_exec(sh->exec);
	sh->exec = tmp;
	sh->env = envtmp;
	return (sh->env);
}

char			**env_builtin(t_shell *sh, char **args)
{
	if (args[1] == NULL)
		ft_puttab(sh->env);
	else if (!ft_strcmp(args[1], "-i"))
		return (env_opt_i(sh, args));
	else if (!ft_strcmp(args[1], "-u"))
		return (rem_env(sh->env, (args + 1)));
	else if (ft_strchr(args[1], '='))
		return (add_env(sh->env, args));
	return (sh->env);
}
