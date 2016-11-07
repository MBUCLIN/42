/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:40:46 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/04 17:13:59 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void		allocate_check(int **check)
{
	if ((*check = (int *)malloc(sizeof(int) * (18 + 1))) == NULL)
		exit(1);
	(*check)[18] = 0;
}

static void		allocate_message(char ***msg)
{
	int		i;

	i = 0;
	if ((*msg = (char **)malloc(sizeof(char *) * (18 + 1))) == NULL)
		exit(1);
	(*msg)[18] = NULL;
}

int				*get_checker(void)
{
	static int		*check = NULL;

	if (check == NULL)
		allocate_check(&check);
	else
		return (check);
	check[0] = EQHNG;
	check[1] = EQIHI;
	check[2] = EQTRP;
	check[3] = EQABT;
	check[4] = EQEMT;
	check[5] = EQFPE;
	check[6] = EQKIL;
	check[7] = EQBUS;
	check[8] = EQSEG;
	check[9] = EQISC;
	check[10] = EQALM;
	check[11] = EQSPD;
	check[12] = EQCPU;
	check[13] = EQFSL;
	check[14] = EQVTA;
	check[15] = EQPSI;
	check[16] = EQUD1;
	check[17] = EQUD2;
	return (check);
}

char			**get_message(void)
{
	static char		**msg = NULL;

	if (msg == NULL)
		allocate_message(&msg);
	else
		return (msg);
	msg[0] = MSGHNG;
	msg[1] = MSGIHI;
	msg[2] = MSGTRP;
	msg[3] = MSGABT;
	msg[4] = MSGEMT;
	msg[5] = MSGFPE;
	msg[6] = MSGKIL;
	msg[7] = MSGBUS;
	msg[8] = MSGSEG;
	msg[9] = MSGISC;
	msg[10] = MSGALM;
	msg[11] = MSGSPD;
	msg[12] = MSGCPU;
	msg[13] = MSGFSL;
	msg[14] = MSGVTA;
	msg[15] = MSGPSI;
	msg[16] = MSGUD1;
	msg[17] = MSGUD2;
	return (msg);
}
