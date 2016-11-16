/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:22:46 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/16 15:02:43 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# define TABSZ 4
# define BUF_SIZE 5
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

# define IF_MVTRBL(m) (m & IS_MVTRBL) //OK
# define IF_MVWRD(m) (m & IS_MVWRD) //OK
# define IF_MVSTND(m) (m & IS_MVSTND) //OK
# define IF_SCRC(m) (m & IS_SCRC) //OK
# define IF_WRDCP(m) (m & IS_WRDCP) //DO
# define IF_HIST(m) (m & IS_HIST) //NEED ALL COMMAND
# define IF_CLEAR(m) (m & IS_CLEAR) // OK

/* Thoose define are used as an array of string */
/* Utility :                                    */
/*     Determine if the input has to be redi-   */
/*  -rected to the heandle function special or  */
/*  normal.                                     */

# define TABLEN 16
# define HISTN {27, 91, 65, 0, 0, 0}
# define HISTP {27, 91, 66, 0, 0, 0}
# define MVOUP {27, 27, 91, 65, 0, 0}
# define MVODO {27, 27, 91, 66, 0, 0}
# define MVOLFT {27, 91, 68, 0, 0, 0}
# define MVORGT {27, 91, 67, 0, 0, 0}
# define MVWLFT {27, 27, 91, 68, 0, 0}
# define MVWRGT {27, 27, 91, 67, 0, 0}
# define MVST {27, 91, 72, 0, 0, 0}
# define MVND {27, 91, 70, 0, 0, 0}
# define WCUT {14, 0, 0, 0, 0, 0}
# define WPST {16, 0, 0, 0, 0, 0}
# define SCUR {24, 0, 0, 0, 0, 0}
# define RCUR {18, 0, 0, 0, 0, 0}
# define BCLR {12, 0, 0, 0, 0, 0}
# define CDEL {127, 0, 0, 0, 0, 0}

# define QTE 1
# define DQTE 2
/* Includes use for the project                 */

# include "error.h"
# include "ft_signal.h"
# include "../../libft/includes/libft.h"
# include "../../ft_printf/includes/ft_printf.h"
# include <stdlib.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>

typedef struct		s_command
{
	char			*command;
	char			*szchar;
	char			*prompt;
	int				pos;
	int				len;
	int				plen;
	int				qmask;
	int				alloc;
}					t_command;

void				ft_prompt(int sig);
void				win_resized(int sig);
int					is_dori(int sig);
int					is_other(int sig);
int					is_message(int sig);

void				del_command(t_command *cmd);
int					canonize_input(char *name);
int					noncanonize_input(char *name);

int					save_cursorpos(int cursor);
int					retr_cursorpos(int cursor);
int					get_cursor(int flag, t_command **cmd);
int					get_line(int cursor);
int					get_column(int cursor);
void				ft_moovecursor(int mv, int up);
void				moove_end(int cursor, t_command *cmd);
int					place_cursor(int oldcol, int cursor, t_command *cmd);
int					get_tabszst(int pos);

t_list				*get_env(t_list *env);
char				*ft_getenv(char *variable);

void				ft_termstr(char *id);
void				ft_termgoto(char *id, int c, int l);
void				delete_char(void);
void				insert_char(int c);
int					left_moove(int cursor, int szchar);
void				right_moove(t_command *cmd, int n);
void				recreate(t_command **cmd, int len);

t_command			**set_command(t_command **cmd);
t_command			**ft_getcommand(void);
void				rewrite_end(t_command **cmd);

int					check_quotelvl(int c);
void				insert_end(t_command **cmd, char *buf, int cursor);
void				inserton_str(t_command **cmd, int len);
int					insert_buf(t_command **cmd, char *buf, int cursor, int len);

void				handle_wcp(char *buf, t_command **cmd);
void				handle_scrc(char *buf, t_command **cmd);
void				handle_stnd(char *buf, t_command **cmd);
void				handle_mvwrd(char *buf, t_command **cmd);
void				handle_trbl(char *buf, t_command **cmd);
void				handle_del(t_command **cmd);
void				handle_special(char *buf, t_command **cmd);
int					handle_normal(char *buf, t_command **cmd);

char				*init_noncanon_read(void);
t_command			*read_loop(char *prompt, int mask, char *command);

#endif
