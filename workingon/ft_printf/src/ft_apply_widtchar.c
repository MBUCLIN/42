#include "../includes/ft_printf.h"

char		*ft_apply_widtchar(char *info, char *conv, int adj)
{
	int		sizew;
	char	*width;
	int		len;

	len = ft_strlen(conv);
	width = NULL;
	sizew = ft_getwidth(info);
	free(info);
	if (sizew > len)
		if (!(width = (char *)ft_memalloc(sizeof(char) * (sizew - len))))
			return (NULL);
	if (!width)
		return (conv);
	ft_memset(width, ' ', sizew - len);
	if (adj == 'r')
		return (ft_strjoindfree(conv, width));
	return (ft_strjoindfree(width, conv));
}
