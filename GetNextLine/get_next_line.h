/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 17:43:19 by mbuclin           #+#    #+#             */
/*   Updated: 2016/01/27 14:16:38 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 180
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_readed
{
	char			*lrd;
	int				fd;
	struct s_readed	*next;
}					t_readed;

int					get_next_line(int const fd, char **line);

#endif
