/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:49:04 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/23 16:35:13 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H
# define FT_SIGNAL_H

/*
** Define the signals that may print error message
** in exec mode
*/
# define MSGSIGSZE 18
# define EQHNG 0b1
# define EQIHI 0b100
# define EQTRP 0b101
# define EQABT 0b110
# define EQEMT 0b111
# define EQFPE 0b1000
# define EQKIL 0b1001
# define EQBUS 0b1010
# define EQSEG 0b1011
# define EQISC 0b1100
# define EQALM 0b1110
# define EQSPD 0b10001
# define EQCPU 0b11000
# define EQFSL 0b11001
# define EQVTA 0b11010
# define EQPSI 0b11011
# define EQUD1 0b11110
# define EQUD2 0b11111

/*
** Define the message printed by signals in exec mode
*/
# define MSGHNG "hangup	"
# define MSGIHI "illegal hardware instruction	"
# define MSGTRP "trape trace	"
# define MSGABT "abort	"
# define MSGEMT "EMT instruction	"
# define MSGFPE "floating point exception	"
# define MSGKIL "killed	"
# define MSGBUS "bus error	"
# define MSGSEG "segmentation fault	"
# define MSGISC "invalid system call	"
# define MSGALM "alarm	"
# define MSGSPD "suspended (signal)	"
# define MSGCPU "cpu limit exceeded	"
# define MSGFSL "file size linut exceeded	"
# define MSGVTA "virtual time alarm	"
# define MSGPSI "profil signal	"
# define MSGUD1 "user-defined signal 1	"
# define MSGUD2 "user-defined signal 2	"

# include <signal.h>

/*
** Function that handle signal from shell
** They are called only in shell mode
** (edit command/parsing/tokenization)
*/
int			place_cursor(int oldcol, int cursor, t_command *cmd);
void		win_resize(int sig);
void		ft_prompt(int sig);
/*
** Function that initialize array of string or masks
*/
int			*get_checker(void);
char		**get_message(void);
/*
** Function that gives the type of signal
** (default or ignore, win or ^C, display a message)
*/
int			is_dori(int sig);
int			is_other(int sig);
int			is_message(int sig);
/*
** Function that jump to shell mode or exec mode
*/
void		ft_changesignal(int sig, int pid, char *name);

#endif
