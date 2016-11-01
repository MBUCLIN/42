/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:46:21 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/01 11:24:00 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int			get_tabszst(int pos)
{
	int		colpos;
	int		col;

	col = get_colsz();
	colpos = (pos % col);
	if (colpos - col >= -4)
		return (-(colpos - col));
	return (-((colpos % 4) - 4));
}
