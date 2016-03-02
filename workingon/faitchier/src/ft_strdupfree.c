#include "../includes/ft_printf.h"

char	*ft_strdupfree(char *s)
{
	char	*dest;
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dest[len] = '\0';
	dest = ft_memcpy(dest, s, len);
	free(s);
	s = NULL;
	return (dest);
}
