#include "../includes/ft_printf.h"

char		*ft_extract_conv(char *start)
{
	int		i;

	i = 0;
	while (start[i])
	{
		if (ft_isconv(start[i]))
			return (ft_strsub(start, 0, i + 1));
		i++;
	}
	return (NULL);
}
