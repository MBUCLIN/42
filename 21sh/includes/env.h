/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:13:32 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/21 13:46:48 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# define FTSHLVL "SHLVL="
# define FTPWD "PWD="
# define FTPATH "PATH="
# define ENVARRAY { FTSHLVL, FTPWD, FTPATH }

# include "../../libft/includes/libft.h"

t_list		*get_env(t_list *env);
char		*ft_setenv(char *name, char *value);
char		*ft_getenv(char *variable);
void		create_known(void);
void		create_env(void);

#endif
