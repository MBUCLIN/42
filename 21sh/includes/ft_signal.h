/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:49:04 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/04 17:47:45 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H
# define FT_SIGNAL_H

/* Thoose define are used to check th signal that print an error message **
** Could be use for get the string to write on error                     **
** EQSIG == [EQ][NAME]                                                   */

# define MSGSIGSZE 18

# define EQHNG 0b1 // hangup :: 1
# define EQIHI 0b100 // illegal hardware instruction :: 4
# define EQTRP 0b101 // trace trap :: 5
# define EQABT 0b110 // abort :: 6
# define EQEMT 0b111 // EMT instruction :: 7
# define EQFPE 0b1000 // floating point exception :: 8
# define EQKIL 0b1001 // killed :: 9
# define EQBUS 0b1010 // bus error :: 10
# define EQSEG 0b1011 // segmentation fault :: 11
# define EQISC 0b1100 // invalid system call :: 12
# define EQALM 0b1110 // alarm :: 14
# define EQSPD 0b10001 // suspended (signal) :: 17
# define EQCPU 0b11000 // cpu limit exceeded :: 24
# define EQFSL 0b11001 // file size limit exceeded :: 25
# define EQVTA 0b11010 // virtual time alarm :: 26
# define EQPSI 0b11011 // profil signal :: 27
# define EQUD1 0b11110 // user-defined signal 1 :: 30
# define EQUD2 0b11111 // user-defined signal 2 :: 31

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

int			*get_checker(void);
char		**get_message(void);
void		ft_changesignal(int sig, int pid, char *name);
#endif
