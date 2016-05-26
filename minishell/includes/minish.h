/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minish.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:50:00 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/26 18:20:29 by mbuclin          ###   ########.fr       */
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
	int				access;
}					t_exec;

typedef struct		s_shell
{
	char			**env;
	char			*prompt;
	t_path			*path;
	t_exec			*exec;
}					t_shell;

char				*read_command(char *line, int n);
char				*search_prompt(char *option, char **env);
t_path				*initiate_path(void);
t_shell				*initiate_shell(char **env, char *prompt);

#endif
