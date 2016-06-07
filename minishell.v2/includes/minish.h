/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:50:00 by mbuclin           #+#    #+#             */
/*   Updated: 2016/06/07 16:10:29 by mbuclin          ###   ########.fr       */
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

void				end_minishell(int exitval);
void				ft_perror(char *msg, char *more);

t_exec				*initiate_exec(void);
char				*get_commandname(t_sehll *shell, char (command);
t_exec				*find_commandtype(t_shell *shell, char *command);
char				*read_command(char *line, int n);

int					create_pathenv(char ***cpy, char *name, char *content);
int					create_pathbinenv(char ***cpy);
int					create_underscore(char ***cpy, char *name, char *content);
char				*read_etcpaths(void);
char				**recreate_env(void);
char				**initiate_env(char **env);

t_path				*initiate_path(void);
char				*create_prompt(int opt, char **env);
char				*search_prompt(int option, char **env);
int					search_option(char *option);
t_shell				*initiate_shell(char **env, char *prompt);

#endif
