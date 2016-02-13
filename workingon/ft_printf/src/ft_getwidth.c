int		ft_getwidth(char *info)
{
	int		i;

	i = 0;
	while (info[i])
	{
		if ((info[i] > 0 && info[i] <= '9') && info[i - 1] == '.')
			while (info[i] >= '0' && info[i] <= '9')
				i++;
		if ((info[i] > '0' && info[i] <= '9') && info[i - 1] != '.')
			return (ft_atoi((info + i)));
		i++;
	}
	return (-1);
}
