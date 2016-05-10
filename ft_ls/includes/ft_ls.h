/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:18:11 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/10 17:21:42 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
//# include <uuid/uuid.h>
# include <time.h>
# include <inttypes.h>
# include "../libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include "ft_ls_struct.h"

void		*del_name(t_name *head);
void		*del_info(t_info *info);
void		*del_all(t_all *head);
void		*del_only_file(t_all *head, int option);
void		print_info(t_all *node);
void		print_name(t_all *node);
char		*print_mode(int mode);
void		print_node(t_all *node);
void		print_all(t_all *head);
char		*create_path(char *last_path, char *name);
t_name		*new_name(char *name, char *path);
t_info		*new_info(t_name *name, int option);
t_all		*new_node_all(t_name *name, int option);
int			ft_puterror(char *msg);
int			total_size(t_all *head, int option);
t_all		*last_node(t_all *head);
t_maxl		*get_len_max(t_all *head);
char		get_filetype(int mode);
char		*get_right(char *line, int mode, int mult);
int			need_minor(struct stat buf, int mode);
int			need_major(struct stat buf, int mode);
char		*get_line_mode(int mode);
int			get_time(struct stat buf, int time, int t);
char		*get_str_time(char *line, t_all *node);
char		*get_date_year(time_t tfile);
char		*get_date(time_t tfile);
char		*get_group_name(gid_t gid);
char		*get_user_name(uid_t uid);
char		*get_grus_name(t_info *node);
char		*get_line_minmaj(char *line, t_info *node, t_maxl *max);
char		*get_size_or_minmaj(char *line, t_info *node, t_maxl *max);
char		*add_linked_path(t_all *node, char *line);
char		*get_line_print(t_all *node, t_maxl *max);
t_all		*sort_list(t_all *all, int option);
int			check_times_option(int option);
int			check_dir(t_all *node, int option);
char		*choose_line(t_all *node, t_maxl *max, int option);
t_all		*print_dir(t_all *head, t_maxl *max, int option);
t_all		*print_file(t_all *head, int option);
int			error_option(char *arg_er);
int			check_option(char *arg);
int			after_option(char **arg, char *option);
int			init_option(int ac, char **av);
t_all		*insert(t_all *head, t_all *new, t_all *node);
t_all		*import_from_else(t_all *head, t_all *new, t_all *node, int opt);
t_all		*import_from_time(t_all *head, t_all *nodei, int option);
t_all		*import(t_all *head, t_all *node, int option);
t_all		*read_dir(t_all *node, DIR *dir, int option);
int			get_dir_content(t_all **node, int option);
t_all		*read_dir_arg(t_all *head, int option);
t_all		*recursive(t_all *head, int option);
t_all		*recup_args(int ac, char **av, int option);

#endif
