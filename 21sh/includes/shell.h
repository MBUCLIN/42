/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:22:46 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/02 16:11:19 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# define TABSZ 4
# define BUF_SIZE 1024
# define LOCAT 0b1
# define LENGT 0b10

/* Thoose define are used as masks to separate type of special type */

# define IS_DEL 0b0
# define IS_MVTRBL 0b1
# define IS_MVWRD 0b10
# define IS_MVSTND 0b100
# define IS_CLEAR 0b1000
# define IS_HIST 0b10000
# define IS_SCRC 0b100000
# define IS_WRDCP 0b1000000

/* Thoose macro are used to choose function */

# define IF_MVTRBL(m) (m & IS_MVTRBL)
# define IF_MVWRD(m) (m & IS_MVWRD)
# define IF_MVSTND(m) (m & IS_MVSTNT)
# define IF_SCRC(m) (m & IS_SCRC)
# define IF_WRDCP(m) (m & IS_WRDCP)
# define IF_HIST(m) (m & IS_HIST)
# define IF_CLEAR(m) (m & IS_CLEAR)

/* Thoose define are used as an array of string */
/* Utility :                                    */
/*     Determine if the input has to be redi-   */
/*  -rected to the heandle function special or  */
/*  normal.                                     */

# define TABLEN 16
# define HISTN {27, 91, 65, 0, 0, 0} //
# define HISTP {27, 91, 66, 0, 0, 0} //
# define MVOUP {27, 27, 91, 65, 0, 0} //
# define MVODO {27, 27, 91, 66, 0, 0} //
# define MVOLFT {27, 91, 68, 0, 0, 0} //
# define MVORGT {27, 91, 67, 0, 0, 0} //
# define MVWLFT {27, 27, 91, 68, 0, 0} //
# define MVWRGT {27, 27, 91, 67, 0, 0} //
# define MVST {27, 91, 72, 0, 0, 0} //
# define MVND {27, 91, 70, 0, 0, 0}
# define WCUT {14, 0, 0, 0, 0, 0} //
# define WPST {16, 0, 0, 0, 0, 0} //
# define SCUR {24, 0, 0, 0, 0, 0}
# define RCUR {18, 0, 0, 0, 0, 0}
# define BCLR {12, 0, 0, 0, 0, 0} //
# define CDEL {127, 0, 0, 0, 0, 0}

# define KEYTAB { HISTN, HISTP, MVOUP, MVODO, MVOLFT, MVORGT, MVWLFT, MVWRGT,\
					MVST, MVND, WCUT, WPST, SCUR, RCUR, BCLR, CDEL }

/* Includes use for the project                 */

# include "error.h"
//# include "../libft/includes/libft.h" // replacement
# include "../../libft/includes/libft.h"
//# include "../ft_printf/includes/ft_printf.h" // replacement
# include "../../ft_printf/includes/ft_printf.h"
# include <stdlib.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>

typedef struct		s_command
{
	char			*command; /* String command : contain char         */
	char			*szchar;  /* String command len : contain char len */
	int				pos;      /* Position command : index of command   */
	int				len;      /* length command : ..................   */
}					t_command;

int					canonize_input(char *name);
int					noncanonize_input(char *name);

int					get_cursor(int flag, t_command **cmd);
int					place_cursor(int oldcol, int cursor);
int					get_tabszst(int pos);
int					get_colsz(void);

char				*search_env(char *var, t_list *env);

void				ft_termstr(char *id);
void				ft_termgoto(char *id, int c, int l);
void				delete_char(void);
void				insert_char(int c);
void				left_moove(int cursor);
void				right_moove(t_command *cmd);
void				recreate(t_command **cmd);

void				rewrite_end(t_command **cmd);

void				handle_trbl(char *buf, t_command **cmd);
void				handle_del(t_command **cmd);
void				handle_special(char *buf, t_command **cmd);
void				handle_normal(int c, t_command **cmd);
char				*read_loop(t_list *env);

#endif
