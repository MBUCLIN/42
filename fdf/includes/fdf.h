/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 15:59:32 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/25 13:29:36 by mbuclin          ###   ########.fr       */
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
# define WIN_H 1280

void		print_y(int *y, size_t size);
void		print_value_map(t_list *head);
void		del_map(void *y, size_t size);
void		del_iso(t_iso *iso);
void		del_img(void *mlx, t_img *img);
void		del_win(t_win *win);
void		del_event(t_all *ev);
int			check_number(char **split, int size);
int			check_line(char *line);
int			check_map(t_list *head);
int			check_coordonne(t_cdn *c, int h);
int			check_wha(t_iso *iso);
int			get_z(int *y, int x);
t_iso		*get_tile(t_iso *iso, t_img *img);
int			get_max_z(t_list *map);
int			convert_split(char **split, t_list **new);
int			stock_map(char *line, t_list **map);
t_list		*read_file_map(int fd);
t_list		*open_map(char *filename);
t_iso		*initiate_iso(t_img *img);
t_img		*initiate_image(t_all *ev);
t_win		*initiate_window(void);
t_all		*initiate_mlx(t_all *ev);
void		end_fdf(t_all *ev);
int			key_event(int keycode, t_all *ev);
int			few_x_for_one_y(t_img **img, t_iso *iso, t_cdn *c);
int			few_y_for_one_x(t_img **img, t_iso *iso, t_cdn *c);
int			straight_line(t_img **img, t_iso *iso);
int			calcul_iso(int x, int y, t_iso *iso, int xy);
t_iso		*get_depart_point_line(t_all *ev, int i, int j, int n);
int			add_line(t_all **ev, t_list *node, int i, int j);
int			fill_image(t_all **ev, t_list *map);
t_img		*new_image(t_win *win);
int			draw_image(t_all **ev);

#endif
