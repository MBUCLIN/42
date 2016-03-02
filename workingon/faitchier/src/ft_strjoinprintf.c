#include "../includes/ft_printf.h"

int			cpy_stringfree(char *dest, char *src, int lsrc)
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
	return (i);
}

char		*ft_strjoinprintf(char *s1, char *s2, int size1)
{
	char		*join;
	int			size;
	int			n;

	size = size1 + ft_strlen(s2) + 1;
	join = NULL;
	if (!(join = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	join[size - 1] = '\0';
	n = cpy_stringfree(join, s1, size1);
	cpy_stringfree((join + n), s2, ft_strlen(s2));
	return (join);
}
