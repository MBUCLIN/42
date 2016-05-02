/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:18:11 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/27 18:46:47 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_ls_struct.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include "../libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"

void		*del_name(t_name *head);
void		*del_info(t_info *info);
void		*del_all(t_all *head);
void		print_name(t_all *head);
t_name		*new_name(char *name, char *path);
t_all		*new_node_all(t_name *name, t_info *info);
int			ft_puterror(char *msg);
int			error_option(char *arg_er);
int			check_option(char *arg);
int			after_option(char **arg, char *option);
int			init_option(int ac, char **av);
t_all		*recup_args(int ac, char **av);

#endif
