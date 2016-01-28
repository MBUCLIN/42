#include "includes/libft.h"

static int		check_base(char *base)
{
	size_t		i;
	size_t		j;
	int			match;

	i = -1;
	if (base == NULL || ft_strlen(base))
		return (0);
	match = 0;
	while (base[++i])
	{
		j = -1;
		while (base[++j])
			if (base[j] == base[i])
				match++;
		if (match != 1)
			return (0);
		match = 0;
	}
	return (1);
}

static int		get_size(size_t nbr, size_t size)
{
	size_t		len;

	len = 0;
	while (nbr)
	{
		len++;
		nbr = nbr / size;
	}
	return (len);
}

char	*ft_sitoabase(size_t nbr, char *base)
{
	char	*convert;
	size_t	sbase;
	int		i;

	if (!(check_base(base)))
		return (NULL);
	sbase = ft_strlen(base);
	i = get_size(nbr, sbase);
	ft_putnbr(i);
	ft_putstr("....");
	if (!(convert = (char *)ft_memalloc(sizeof(char) * i)))
		return (NULL);
	i--;
	while (--i >= 0)
	{
		if (nbr)
		{
			convert[i] = base[nbr % sbase];
			nbr = nbr / sbase;
		}
	}
	return (convert);
}
