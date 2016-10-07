/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_incstruc.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:39:13 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/07 16:44:09 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_INCSTRUC_H
# define PUSH_SWAP_INCSTRUC_H

# include "../../libft/includes/libft.h"
# include "../../ft_printf/includes/ft_printf.h"
# define NB_OPTION 3
# define NUMBER 0
# define COLOR 1
# define STATE 2
# define RA 2
# define RRA 4
# define SA 8
# define PA 16
# define PB 32
# define RB 64
# define RRB 128
# define SB 256
# define SS 512
# define RR 1024
# define RRR 2048

typedef struct			s_pile
{
	int					num;
	int					pos;
	int					tmp;
	struct s_pile		*next;
}						t_pile;

typedef struct			s_cmd
{
	char				*command;
	int					turn;
	struct s_cmd		*next;
}						t_cmd;

typedef struct			s_sop
{
	int					next;
	int					toget;
}						t_sop;

typedef struct			s_moov
{
	int					stack;
	int					action;
	int					wayrot;
	int					n_rot;
	int					n;
	struct s_moov		*next;
}						t_moov;

typedef struct			s_inf
{
	int					stack;
	int					distfrom;
	int					dist;
	int					distto;
	int					n;
	struct s_inf		*next;
}						t_inf;

typedef struct			s_turn
{
	t_pile				*a;
	t_pile				*b;
	t_inf				*info;
	t_moov				*moov;
	t_cmd				*command;
}						t_turn;

#endif
