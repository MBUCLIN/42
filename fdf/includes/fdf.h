/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:59:32 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/19 17:59:13 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"
//# include "fdf_structure.h"

void		print_y(int *y, size_t size);
void		print_value_map(t_list *head);
void		del_map(void *y, size_t size);
int			check_line(char *line);
int			check_map(t_list *head);
int			convert_split(char **split, t_list **new);
int			stock_map(char *line, t_list **map);
t_list		*read_file_map(int fd);
t_list		*open_map(char *filename);

#endif
