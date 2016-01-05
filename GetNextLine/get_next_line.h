/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 17:43:19 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/03 16:05:33 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUF_SIZE 150
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_readed
{
	char			*lrd;
	int				fd;
	struct s_readed	*next;
}					t_readed;

t_readed			*get_fd(t_readed **last, int const fd);
int					search_last_read(t_readed *lrd, char **line);
int					read_fd(int const fd, t_readed *lrd, char **line);
void				del_nod(t_readed *last, int const fd);
int					get_next_line(int const fd, char **line);

#endif
