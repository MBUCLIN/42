/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:13:32 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/23 16:31:46 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/*
** Define to name the variables that we create
** if the parent env is NULL
*/
# define FTSHLVL "SHLVL="
# define FTPWD "PWD="
# define FTPATH "PATH="
# define FTHOME "HOME="

/*
** Function that set||get the environment or
** env variables
*/
t_list		*get_env(t_list *env);
char		*ft_setenv(char *name, char *value);
char		*ft_getenv(char *variable);
/*
** Function that we call to create our environment
** if the parent one is null (extern char **environ)
*/
void		create_shlvl(char *shlvl);
void		create_pwd(char *pwd);
void		create_path(char *path);
void		create_env(void);

#endif
