#include "../includes/ft_printf.h"

char		*ft_strdupprintf(const char *src, int size)
{
	char	*dup;

	dup = NULL;
	if (!(dup = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memcpy(dup, src, size);
	dup[size] = 0;
	return (dup);
}
