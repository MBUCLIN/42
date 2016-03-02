#include "../includes/ft_printf.h"

int		ft_apply_widtchar(char *info, char **conv, int adj, int len)
{
	int		sizew;
	char	*width;

	width = NULL;
	sizew = ft_getwidth(info);
	free(info);
	if (sizew > len && len > 0)
	{
		if (!(width = (char *)malloc(sizeof(char) * (sizew - len))))
			return (0);
		width[sizew - len] = '\0';
	}
	if (!width)
		return (len);
	ft_memset(width, ' ', sizew - len);
	if (adj == 'r')
	{
		if (!(*conv = ft_strjoinprintf(*conv, width, len)))
			return (0);
	}
	else
		if (!(*conv = ft_strjoinprintf(width, *conv, sizew - len)))
			return (0);
	return (len + (sizew - len));
}
