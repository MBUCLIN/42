/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:50:00 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/27 17:49:17 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H

# include <unistd.h>
# include "../libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"

typedef struct		s_path
{
	char			*cpath;
	char			*ppath;
}					t_path;

typedef struct		s_exec
{
	char			*xpath;
	pid_t			xpid;
	char			*xname;
	char			**args;
}					t_exec;

typedef struct		s_shell
{
	char			**env;
	char			*prompt;
	t_path			*path;
	t_exec			*exec;
}					t_shell;

void				del_path(t_path *path);
void				del_exec(t_exec *exec);
void				del_shell(t_shell *shell);
void				end_minishell(t_shell *shell);
void				ft_perror(char *msg, char *more);
char				*get_commandname(char *command);
char				*get_linecommand(char *line);
char				*read_command(char *line, int n);
char				*search_prompt(char *option, char **env);
int					fill_access(char (*access)[256], char *path, char *name);
int					search_pathofname(t_shell **sh, char *xname,\
										char **pathes);
int					search_cpath(t_shell **shell, char *name, char *cpath);
int					search_envpath(char *xname, t_shell **sh);
int					find_command(t_shell **shell, char *command);
t_exec				*initiate_exec(char *path, char *xname);
t_path				*initiate_path(void);
t_shell				*initiate_shell(char **env, char *prompt);

#endif
