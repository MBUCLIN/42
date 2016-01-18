#ifndef FT_PRINTF_IS_H
# define FT_PRINTF_IS_H
# include "libft/libft.h"
# include "ft_printf_pro.h"
# include <stdarg.h>

typedef struct			s_func
{
	void				*func;
	int					narg;
	struct s_func		*next;
}						t_func;

#endif
