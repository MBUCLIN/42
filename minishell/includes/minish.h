/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <mbuclin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:50:00 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/07 16:41:47 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISH_H
# define MINISH_H

# include <unistd.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/wait.h>
# include "../../libft/includes/libft.h"
# include "../../ft_printf/includes/ft_printf.h"

typedef struct		s_exec
{
	char			*xpath;
	char			*xname;
	char			**args;
}					t_exec;

typedef struct		s_shell
{
	int				opt;
	char			**env;
	char			*prompt;
	t_list			*path;
	t_exec			*exec;
}					t_shell;

void				end_minishell(int exitval);
void				ft_perror(char *msg, char *more);
void				msg_signal(int sig, char *name);
int					error_unset(char **arg);
int					error_set(char **arg);
int					error_init(char **arg);

char				**remove_var(char *var, char **env, int len);
void				del_path(t_list *path);
void				del_exec(t_exec *exec);

void				change_path(t_list **node, int i);
char				*change_prompt(t_shell *shell);
char				**change_args(char **args, char **env);
char				**change_underscore(t_exec *exec, char **env);
int					env_to_change(char **env, char *arg);
char				**env_alloc(int len);
char				**process_argenv(char **arg, t_exec *exec);

t_list				*goto_pathhome(char **env, t_list *path);
t_list				*goto_newpath(int n, t_list *path, char *arg);
t_list				*goto_slash(t_list *path, char *arg);
char				*get_var(char *arg, char **env);
char				*cut_envvar(char *arg);
int					check_isdir(char *arg, char *cpath, char *exec);
int					is_exec(char *path);

int					fill_access(char (*access)[256], char *path, char *xname);
t_exec				*search_cpath(t_exec *exec);
char				*search_envpath(char *xname, t_shell *sh);
char				**get_arguments(char *command, char ***arg);
t_exec				*initiate_exec(void);
t_exec				*find_commandtype(t_shell *shell, char *command);
char				*read_command(char *line, int n);

int					create_pathenv(char ***cpy, char *name, char *content);
int					create_pathbinenv(char ***cpy);
int					create_underscore(char ***cpy, char *name, char *content);
char				*read_etcpaths(void);
char				**recreate_env(void);
char				**initiate_env(char **env);

t_list				*initiate_path(void);
char				*create_prompt(int opt, char **env);
char				*search_prompt(int option, char **env);
int					search_option(char *option);
t_shell				*initiate_shell(char **env, char *prompt);

char				**rem_env(char **env, char **arg);
char				**add_env(char **env, char **args);
char				**env_builtin(t_shell *sh, char **args);
t_list				*ft_chdir(char **env, t_list *path, char **args);
void				exec_command(t_shell *sh);
void				apply_command(t_exec *exec, t_shell **shell);
#endif
