/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:22:46 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/25 14:10:12 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# define BUF_SIZE 100

/*
** Includes my libs
*/
# include "../../libft/includes/libft.h"
# include "../../ft_printf/includes/ft_printf.h"

/*
** Includes system
*/
# include <dirent.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>

/*
** Project includes
*/
# include "command.h"
# include "error.h"
# include "env.h"
# include "ft_signal.h"

/*
** Function that switch to canonized input or noncanonized one
*/
int					canonize_input(char *name);
int					noncanonize_input(char *name);
/*
** Function that save the command in .42shhistory file
*/
//t_list				*save_history(char *command);
/*
** Function that search the home directory
** (The most recent modifyed directory in /Users path)
*/
char				*ft_gethome(void);

#endif
