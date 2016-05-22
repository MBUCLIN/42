/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structure.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 14:41:59 by mbuclin           #+#    #+#             */
/*   Updated: 2016/05/22 17:35:06 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTURE_H
# define FDF_STRUCTURE_H

typedef struct		s_cdn
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
}					t_cdn;

typedef struct		s_iso
{
	int				coef;
	int				x;
	int				y;
	int				color;
	int				z1;
	int				z2;
	t_cdn			*cdn;
}					t_iso;

typedef struct		s_win
{
	int				pos_x;
	int				pos_y;
	void			*mlx;
	void			*win;
}					t_win;

typedef struct		s_all
{
	t_win			*win;
	t_list			*map;
	t_img			*img;
	t_iso			*iso;
}					t_all;

#endif
