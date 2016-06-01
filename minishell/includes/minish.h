/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:50:00 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/01 16:38:42 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H

# include <unistd.h>
# include <signal.h>
# include <sys/stat.h>
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
	int				opt;
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
void				errorformat(char *err);
char				*bad_arg(char **arg);
void				msg_signal(int sig, char *name);
void				ft_kill(int sig);
int					reconstruct_path(t_shell **shell);
int					goto_argpath(t_path *path, char *arg);
int					goto_lastpath(t_path *path);
t_path				*goto_pathhome(char **env, t_path *path);
t_path				*goto_newpath(int n, t_path *path, char *arg);
int					check_args(char **args);
int					check_isdir(char *arg, char *cpath);
int					check_exec(char *path);
int					check_argenv(char *arg);
char				*change_prompt(t_shell *shell);
char				*get_commandname(char *command);
char				*get_linecommand(char *line);
char				**get_arguments(char *command);
char				*get_var(char *arg, char **env);
t_path				*ft_chdir(char **env, t_path *path, char **args);
char				**add_env(char **env, char **arg);
char				**rem_env(char **env, char **arg);
void				exec_command(t_shell *sh);
char				*read_command(char *line, int n);
char				*search_prompt(char *option, char **env);
int					fill_access(char (*access)[256], char *path, char *name);
int					search_pathofname(t_shell **sh, char *xname,\
										char **pathes);
int					search_cpath(t_shell **shell, char *name, char *cpath);
int					search_envpath(char *xname, t_shell **sh);
int					search_option(char *option);
int					find_command(t_shell **shell, char *command);
char				*apply_builtin(t_shell *shell, char *command);
char				*apply_command(t_shell *shell, char *command);
t_exec				*initiate_exec(char *path, char *xname);
t_path				*initiate_path(void);
t_shell				*initiate_shell(char **env, char *prompt);

#endif
