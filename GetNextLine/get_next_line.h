#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "includes/libft.h"

typedef struct		s_readed
{
	char			*lrd;
	char			*lln;
	int				fd;
	struct s_readed	*next;
}					t_readed;

t_readed			*search_fd(t_readed *alst, int const fd);
int					check_last_read(int const fd, t_readed *alst, char *line);
int					get_next_line(int const fd, char *line);

#endif
