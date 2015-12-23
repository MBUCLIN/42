#ifndef FILLIT_INCSTRUC_H
# define FILLIT_INCSTRUC_H

# define BUF_SIZE 21
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct			s_sample
{
	char				**tetri;
	char				c;
	struct s_sample		*next;
}						t_sample;

typedef struct			s_pos
{
	int					y;
	int					x;
}						t_pos;

#endif
