/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:03:46 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/24 16:40:54 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

/*
** Define for the get_cursor function
** LOCAT get the location of the cursor
** LENGT get the location of the end of command
*/
# define LOCAT 0b1
# define LENGT 0b10

/*
** Define for creating a mask to redirect to
** the good handle function (special)
*/
# define IS_DEL 0b0
# define IS_MVTRBL 0b1
# define IS_MVWRD 0b10
# define IS_MVSTND 0b100
# define IS_CLEAR 0b1000
# define IS_HIST 0b10000
# define IS_SCRC 0b100000
# define IS_WRDCP 0b1000000

/*
** Define for redirect to the good handle function (special)
*/
# define IF_MVTRBL(m) (m & IS_MVTRBL)
# define IF_MVWRD(m) (m & IS_MVWRD)
# define IF_MVSTND(m) (m & IS_MVSTND)
# define IF_SCRC(m) (m & IS_SCRC)
# define IF_WRDCP(m) (m & IS_WRDCP)
# define IF_HIST(m) (m & IS_HIST)
# define IF_CLEAR(m) (m & IS_CLEAR)

/*
** Define for cmp with the input from user,
** if the cmp is NULL then it goes to special else
** it goes to normal
*/
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

/*
** Define that give the mask (qmask) for the quoting
** it gives the good prompt of quoting level
*/
# define QTE 1
# define DQTE 2

/*
** structure that is used in the edit command part
** we then keep the command string to be parsed and tokenized
*/
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

/*
** Function that delete all or parts of the t_command
** struct
*/
void				del_command(t_command *cmd);
void				del_cmdhist(t_command *cmd);
/*
** Function that return the size of the tabulation
** for the curent cursor pos (int pos)
*/
int					get_tabszst(int pos);
/*
** Function that return information about the cursor
** (His line, column, the position of the location OR
** the position of the length)
*/
int					get_column(int cursor);
int					get_line(int cursor);
int					get_cursor(int flag, t_command **cmd);
/*
** Function that handle moovements of the cursor
*/
void				ft_moovecursor(int mv, int up);
void				moove_start(int cursor, int co);
void				moove_end(int cursor, t_command *cmd);
int					moove_wrgt(t_command **cmd);
/*
** Function that execute several termcaps
** they don't have any returns so we won't know if it work'd.
** The left_moove function does retrun a integer :
** TRUE : it mooves to the upper line and szchar X left
** FALSE : it mooves one left
*/
int					save_cursorpos(int cursor);
int					retr_cursorpos(int cursor);
void				ft_termgoto(char *id, int c, int l);
void				ft_termstr(char *id);
void				delete_char(void);
void				insert_char(int c);
int					left_moove(int cursor, int szchar, t_command *cmd);
void				right_moove(t_command *cmd, int n);
/*
** Function to save the actual command in a static var
** (use in signal part) or for the rewrite function that is
** called for all function that change the charaters of the command.
** The recreate function realloc the command string and szchar string
** of the t_command struct and set the new value of alloc integer
*/
t_command			**set_command(t_command **cmd);
t_command			**ft_getcommand(void);
void				display_char(int c, int szchar, int cursor);
void				recreate(t_command **cmd, int len);
t_command			*create_command(char *prompt, int mask, char *command);
void				rewrite_end(t_command **cmd);
/*
** Function that handle the insert part of the input redirection
** insert the input (buf) and deal with quotting and new lines
*/
int					check_quotelvl(int c);
void				insert_end(t_command **cmd, char *buf, int cursor);
void				inserton_str(t_command **cmd, int len);
int					insert_buf(t_command **cmd, char *buf, int cursor, int len);
/*
** Function that are called by the special part of the
** input redirection.
*/
void				handle_wcp(char *buf, t_command **cmd);
void				handle_scrc(char *buf, t_command **cmd);
void				handle_stnd(char *buf, t_command **cmd);
void				handle_mvwrd(char *buf, t_command **cmd);
void				handle_trbl(char *buf, t_command **cmd);
void				handle_del(t_command **cmd);
void				handle_history(int way, t_command **cmd);
/*
** Function that handle the input from user
** If the cmp of the buf with the defined string before
** is true then input is redirected to special else it goes
** to normal
*/
void				handle_special(char *buf, t_command **cmd);
int					handle_normal(char *buf, t_command **cmd);
/*
** Function that read input from user
** It read until a new line is entered and
** the quote or double quote level is 0
*/
char				*init_noncanon_read(void);
t_command			*read_loop(char *prompt, int mask, char *command);

#endif
