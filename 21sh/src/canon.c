/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canon.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:46:03 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/26 16:23:01 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

int		canonize_input(char *name)
{
	struct termios		term;
	int					err;

	err = 0;
	if (tgetent(NULL, name) != 1)
		return (0);
	if (tcgetattr(0, &term) == -1)
		err = 1;
	else
	{
		term.c_lflag &= ~(ICANON | ECHO);
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		if (tcsetattr(0, TCSADRAIN, &term) == -1)
			err = 1;
	}
	if (err)
	{
		sherror("21sh", ERRTERM, NULL);
		return (0);
	}
	return (1);
}

int		noncanonize_input(char *name)
{
	struct termios		term;
	int					err;

	err = 0;
	if (tgetent(NULL, name) != 1)
		return (0);
	if (tcgetattr(0, &term) == -1)
		err = 1;
	else
	{
		term.c_lflag |= (ICANON | ECHO);
		if (tcsetattr(0, TCSADRAIN, &term) == -1)
			err = 1;
	}
	if (err)
	{
		sherror("21sh", ERRTERM, NULL);
		return (0);
	}
	return (1);
}
