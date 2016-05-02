/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:18:11 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/02 17:21:42 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <inttypes.h>
# include "../libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include "ft_ls_struct.h"

void		*del_name(t_name *head);
void		*del_info(t_info *info);
void		*del_all(t_all *head);
void		print_info(t_all *node);
void		print_name(t_all *node);
char		*print_mode(int mode);
void		print_node(t_all *node);
void		print_all(t_all *head);
t_name		*new_name(char *name, char *path);
t_info		*new_info(t_name *name, int option);
t_all		*new_node_all(t_name *name, t_info *info);
int			ft_puterror(char *msg);
char		get_filetype(int mode);
char		*get_right(char *line, int mode, int mult);
char		*get_line_mode(int mode);
int			get_time(struct stat buf, int time);
char		*get_group_name(gid_t gid);
char		*get_user_name(uid_t uid);
char		*get_grus_name(t_info *node);
char		*get_line_print(t_all *node, int sizelenm);
int			check_times_option(int option);
int			error_option(char *arg_er);
int			check_option(char *arg);
int			after_option(char **arg, char *option);
int			init_option(int ac, char **av);
t_all		*recup_info(t_all *all, int time);
t_all		*recup_args(int ac, char **av);

#endif
