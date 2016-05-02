/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 14:28:10 by mbuclin           #+#    #+#             */
/*   Updated: 2016/04/27 18:52:14 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_STRUCT_H
# define FT_LS_STRUCT_H

# define OPT_L 1
# define OPT_MR 2
# define OPT_R 4
# define OPT_A 8
# define OPT_T 16

typedef struct		s_name
{
	char			*name;
	char			*path;
}					t_name;

typedef struct		s_info
{
	char			*gr_name;
	char			*us_name;
	int				mode;
	long long		time;
	int				size;
	int				hardl;
}					t_info;

typedef struct		s_all
{
	t_name			*name;
	t_info			*info;
	struct s_all	*next;
}					t_all;

#endif
