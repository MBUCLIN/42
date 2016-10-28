/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:46:21 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/28 13:55:00 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int			get_tabszst(int pos)
{
	int		colpos;
	int		col;

	col = get_colsz();
	colpos = ((pos + 3) % col);
	if (pos == 0)
		return (1);
	return (-((colpos % 4) - 4));
}

int			get_tabsznd(int pos)
{
	int		colpos;
	int		col;

	col = get_colsz();
	colpos = ((pos + 3) % col);
	if (pos == 1)
		return (1);
	else if (colpos % 4)
		return (colpos % 4);
	return (4);
}
