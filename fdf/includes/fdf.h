/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:59:32 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/20 15:44:11 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <limits.h>
# include <mlx.h>
# include "../libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include "fdf_structure.h"
# define WIN_W 1280
# define WIN_H 720

void		print_y(int *y, size_t size);
void		print_value_map(t_list *head);
void		del_map(void *y, size_t size);
int			check_number(char **split, int size);
int			check_line(char *line);
int			check_map(t_list *head);
int			convert_split(char **split, t_list **new);
int			stock_map(char *line, t_list **map);
t_list		*read_file_map(int fd);
t_list		*open_map(char *filename);

#endif
