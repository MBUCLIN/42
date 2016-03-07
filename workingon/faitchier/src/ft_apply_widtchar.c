#include "../includes/ft_printf.h"

static t_printf		*joinwidthleft(t_printf *conv, char *width, int size)
{
	char	*join;
	int		dsize;

	join = NULL;
	dsize = conv->size + size;
	if (!(join = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memcpy(join, width, size);
	ft_memcpy((join + size), conv->opt, conv->size);
	join[size] = 0;
	free(conv->opt);
	conv->opt = NULL;
	if (!(conv->opt = ft_strdupprintf(join, dsize)))
		return (NULL);
	free(join);
	free(width);
	conv->size = dsize;
	return (conv);
}

t_printf			*ft_apply_widtchar(char *info, t_printf *conv, int adj)
{
	int		size;
	char	*width;

	width = NULL;
	size = ft_getwidth(info) - conv->size;
	free(info);
	if (size >= 1)
		if (!(width = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
	if (!width)
		return (conv);

	width[size] = '\0';
	ft_memset(width, ' ', size);
	if (adj == 'r')
		return (ft_strjoinprintf(conv, width, size));
	return (joinwidthleft(conv, width, size));
}
