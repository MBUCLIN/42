/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 13:26:49 by mbuclin           #+#    #+#             */
/*   Updated: 2016/10/20 16:12:03 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

#define ERRMALLOC -1
#define ERRCMDNOTF 0
#define ERRPATHPERM 1
#define ERRTERM 2
#define ERRENV 3

void		sherror(char *name, int errnum, char *file);

#endif
