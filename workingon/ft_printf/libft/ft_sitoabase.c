#include "libft.h"

static int		check_base(char * base)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (i != j && base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int		get_size(size_t nbr, int base)
{
	int		size;

	size = 0;
	while (nbr)
	{
		nbr /= base;
		size++;
	}
	return (size);
}

char			*ft_sitoabase(size_t nbr, char *base)
{
	int		size;
	char	*ret;
	int		div;

	if (!(check_base(base)))
		return (NULL);
	div = ft_strlen(base);
	size = get_size(nbr, div);
	if (!(ret = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	size -= 1;
	while (size >= 0)
	{
		ret[size] = base[nbr % div];
		nbr /= div;
		size--;
	}
	return (ret);
}
