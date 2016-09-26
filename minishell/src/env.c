/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 15:42:44 by mbuclin           #+#    #+#             */
/*   Updated: 2016/09/26 16:08:24 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

char			**rem_env(char **env, char **arg)
{
	int			len;
	int			i;
	char		*var;

	len = ft_tabstrlen(env);
	i = 1;
	if (error_unset(arg) == 1)
		return (env);
	while (arg[i])
	{
		if ((var = get_var(arg[i], env)) != NULL)
		{
			env = remove_var(var, env, len - 1);
			len = len - 1;
			free(var);
			var = NULL;
		}
		i++;
	}
	ft_puttab(env);
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
	int			i;

	i = 1;
	if (error_set(arg) == 1)
		return (env);
	while (arg[i])
	{
		if (env_to_change(env, arg[i]))
			env = arg_exist(env, arg[i]);
		else if ((env = ft_addstrtotab(env, arg[i])) == NULL)
			end_minishell(-1);
		i++;
	}
	ft_puttab(env);
	return (env);
}

static char		**env_opt_i(t_shell *sh, char **args)
{
	t_exec		*tmp;
	char		**envtmp;

	tmp = sh->exec;
	sh->exec = NULL;
	if (error_init(args) == 1)
		return (sh->env);
	sh->exec = find_commandtype(sh, args[ft_tabstrlen(args) - 1]);
	if (sh->exec->xname == NULL)
	{
		del_exec(sh->exec);
		sh->exec = NULL;
	}
	envtmp = sh->env;
	sh->env = NULL;
	sh->env = process_argenv(args, sh->exec);
	exec_command(sh);
	del_exec(sh->exec);
	sh->env = ft_deltabstr(sh->env, ft_tabstrlen(sh->env));
	sh->exec = tmp;
	sh->env = envtmp;
	return (sh->env);
}

char			**env_builtin(t_shell *sh, char **args)
{
	if (args[1] == NULL)
	{
		ft_puttab(sh->env);
		return (sh->env);
	}
	else if (!ft_strcmp(args[1], "-i"))
		return (env_opt_i(sh, args));
	else if (!ft_strcmp(args[1], "-u"))
		return (rem_env(sh->env, (args + 1)));
	return (add_env(sh->env, args));
}
