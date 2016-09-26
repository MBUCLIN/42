/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 14:57:58 by mbuclin           #+#    #+#             */
/*   Updated: 2016/09/06 15:14:47 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minish.h"

static char			*replace_by_var(char *arg, char **env, int st, int size)
{
	char		*srch;
	char		*var;
	char		*rep;

	if ((srch = ft_strsub(arg, st, size)) == NULL)
		end_minishell(-1);
	if (srch[size - 1] != '=')
		if ((srch = ft_strjoinfree(srch, "=")) == NULL)
			end_minishell(-1);
	if ((var = ft_srchenv(srch, env)) == NULL)
	{
		free(srch);
		return (NULL);
	}
	free(srch);
	if ((rep = ft_strdup(var)) == NULL)
		end_minishell(-1);
	return (ft_rpcstr(rep, arg, st - 1, size));
}

static char			*replace_args(char *arg, char **env)
{
	int			i;
	int			st;
	int			ston;

	i = 0;
	ston = 0;
	while (arg[i])
	{
		if (arg[i] == '$')
		{
			ston = 1;
			st = i + 1;
		}
		else if (arg[i] == '=' && ston)
			break ;
		i++;
	}
	return (replace_by_var(arg, env, st, i));
}

char				**change_args(char **args, char **env)
{
	int		i;
	char	*change;

	i = 0;
	while (args[i])
	{
		while (ft_strchr(args[i], '$'))
		{
			change = NULL;
			if ((change = replace_args(args[i], env)) == NULL)
				break ;
			free(args[i]);
			if ((args[i] = ft_strdup(change)) == NULL)
				end_minishell(-1);
			free(change);
		}
		i++;
	}
	return (args);
}

char				**process_argenv(char **arg, t_exec *exec)
{
	int			i;
	int			ex;
	char		**env;

	i = 2;
	ex = 0;
	env = NULL;
	if (arg[i] == NULL)
		return (NULL);
	if (exec != NULL)
		ex = 1;
	if (ft_tabstrlen(arg) > 3)
		env = env_alloc(ft_tabstrlen(arg) - (i + ex));
	if (env)
		while (arg[i])
		{
			if ((ex == 1 && arg[i + 1] != NULL) || ex == 0)
				if ((env[i - 2] = ft_strdup(arg[i])) == NULL)
					end_minishell(-1);
			i++;
		}
	return (env);
}
