#include "../includes/ft_printf.h"

static void			cpy_stringfree(char *dest, char * src, int lsrc)
{
	int		i;

	i = 0;
	while (i < lsrc)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	free(src);
	src = NULL;
}

t_printf		*ft_strjoinprintf(t_printf *print, char *s2, int len2)
{
	char		*join;
	int			size;

	size = print->size + len2;
	join = NULL;
	if (!(join = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	join[size] = '\0';
	cpy_stringfree(join, print->opt, print->size);
	cpy_stringfree((join + print->size), s2, len2);
	if (!(print->opt = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	print->opt[size] = 0;
	ft_memcpy(print->opt, join, size);
	print->size = size;
	free(join);
	return (print);
}
