#include "../includes/ft_printf.h"

char		*ft_strsub(const char *tosub, int sta, int size)
{
	char	*sub;
	int		i;

	i = 0;
	sub = NULL;
	if (size > ft_strlen(tosub) - sta)
		size = ft_strlen(tosub) - sta;
	else if (!(sub = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size && tosub[sta])
	{
		sub[i] = tosub[sta];
		i++;
		sta++;
	}
	return (sub);
}
