/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:03:46 by mbuclin           #+#    #+#             */
/*   Updated: 2016/12/01 13:11:20 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

/*
** Define for the get_cursor (cursor.c) function
** LOCAT get the location of the cursor
** LENGT get the location of the end of command
** CSLINE get the line for LOCAT or LENGT
** CSCOL get the column for LOCAT or LENGT
** NONE get only the LOCAT or the LENGT of the cursor
*/
# define NONE 0b0
# define LOCAT 0b1
# define LENGT 0b10
# define CSLIN 0b1
# define CSCOL 0b10

/*
** Define for creating a mask to redirect to
** the right handle function (handle_special.c)
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
** Define for redirect to the right handle function (handle_special.c)
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
** if the user input compared with those define by
** the function check_special (read_loop.c) is true
** then we can assume that a call to the special function
** handleling is asked (handle_special.c)
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
** it gives the good prompt of quoting level (quoting.c)
** It can also determine the prompt to print
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
/*
** Function that return information about the cursor
** (the line OR column OF the location OR
** the length of the cursor)
** get_tabszst gives the tabulation size for the cursor
*/
int					get_tabszst(int cursor);
int					get_cursor(int flagcmd, int flagcs, t_command **cmd);
/*
** Function that handle moovements of the cursor
** -	ft_moovecursor >> mv moove column int between 0 and COLSZ
** up moove line int < 0 to moove up and > 0 to moove down
** -	moove_start >> moove to the start of the command
** -	moove_end >> moove to the end of the command
** -	moove_wrgt >> moove one word to the right
** used to mv word or to cut word
*/
void				ft_moovecursor(int mv, int up);
void				moove_start(int cursor, int co);
void				moove_end(t_command *cmd);
int					moove_wrgt(t_command **cmd);
/*
** Function that execute several termcaps
** they don't have any returns so we won't know if it work'd.
** The left_moove function retrun a integer :
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
** Function that save the t_command struct given
** or retrieve the last saved t_command struct
*/
t_command			**set_command(t_command **cmd);
t_command			**ft_getcommand(void);
/*
** Function that set the command && szchar variable
** in the t_command struct
*/
int					command_settobuf(t_command **cmd, int c, int cursor);
/*
** Function to display on the stream a character 'c'
** 'szchar' times if the 'cursor' is >= 0 it will use insert_char
** else if it is < 0 it will only write the character
*/
void				display_char(int c, int szchar, int cursor);
/*
** Function that allocate or realocate some memory for the
** command and szchar variable in t_command struct
*/
void				recreate(int len);
t_command			*create_command(char *prompt, int mask, char *command);
/*
** Function thay rewrite the end of the command starting to pos
** ending to len of the last saved t_command struct
*/
void				rewrite_end(void);
/*
** Function that handle the insert part of the input redirection
** insert the input (buf) and deal with quotting and new lines
*/
int					command_insert(char *buf);
/*
** Check and set the quotting level
** it also set the mask in the t_command struct
*/
int					check_quotelvl(int c);
/*
** Function that are called by the special part of the
** input redirection.
*/
void				handle_wcp(char *buf, t_command **cmd);
void				handle_mvwrd(char *buf, t_command **cmd);
void				handle_trbl(char *buf);
void				handle_del(t_command **cmd);
void				handle_history(int way, t_command **cmd);
/*
** Function that handle the input from user
*/
void				handle_special(char *buf, t_command **cmd);
int					handle_normal(char *buf);
/*
** Function that read input from user
** It read until a new line is entered and
** the quote or double quote level is 0
*/
char				*init_noncanon_read(void);
t_command			*read_loop(char *prompt, int mask, char *command);

#endif
