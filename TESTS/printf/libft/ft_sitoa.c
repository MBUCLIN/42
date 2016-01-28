#include "includes/libft.h"

static int		check_size(ssize_t nbr)
{
	int		size;

	size = 0;
	if (nbr < 0)
	{
		size = 1;
		nbr = nbr * -1;
	}
	while (nbr)
	{
		size++;
		nbr = nbr / 10;
	}
	return (size);
}

char			*ft_sitoa(ssize_t nbr)
{
	char	*str;
	int		size;

	if (nbr * -1 - 1 == 9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	else if (!nbr)
		return (ft_strdup("0"));
	size = check_size(nbr);
	if (!(str = (char *)ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	while (--size >= 0 && str[size] != '-')
	{
		str[size] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	return (str);
}
