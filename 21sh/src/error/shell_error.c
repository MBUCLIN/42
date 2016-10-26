/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:15:00 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/20 16:12:50 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/error.h"
#include "../../../libft/includes/libft.h"

static void		ft_puterror(char *name, char *msg, char *file)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(msg, 2);
	ft_putendl_fd(2, file);
}
void			sherror(char *name, int errnum, char *file)
{
	if (errnum == ERRMALLOC)
		ft_puterror(name, ": Memory alocation error.", file);
	else if (errnum == ERRCMDNOTF)
		ft_puterror(name, ": Command not found: ", file);
	else if (errnum == ERRPATHPERM)
		ft_puterror(name, ": Permission denied: ", file);
	else if (errnum == ERRTERM)
		ft_puterror(name, ": TERM failed to change.", file);
	else if (errnum == ERRENV)
		ft_puterror(name, ": Environment variable not set: ", file);
	else
		ft_puterror(name, ": Errnum wrong value.", file);
}
