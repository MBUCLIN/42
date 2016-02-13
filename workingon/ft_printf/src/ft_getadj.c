int		ft_getadj(char *info)
{
	int		i;
	int		adj;

	i = 0;
	adj = 0;
	while (info[i])
	{
		if (info[i] == '-')
			return ('r');
		else if (info[i] == '0')
			adj = 'l';
		i++;
	}
	return (adj);
}
