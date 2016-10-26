/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:52:10 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/25 16:59:30 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int		get_colsz(void)
{
	struct winsize		winsz;

	if (ioctl(0, TIOCGWINSZ, &winsz) == -1)
		return (-1);
	return (winsz.ws_col);
}
