/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 13:26:49 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/23 16:33:25 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*
** Define the possible errnum
** for our shell
*/
# define ERRMALLOC -1
# define ERRCMDNOTF 0
# define ERRPATHPERM 1
# define ERRTERM 2
# define ERRENV 3
# define ERRSTREAM 4

/*
** function that print error message
** sherror print message then return to the edit of command
** ft_exitshell print message then exit with -1 value the shell
*/
void		sherror(char *name, int errnum, char *file);
void		ft_exitshell(char *name, int errnum, char *file);

#endif
