int		ft_isflag(char c)
{
	if (c == '#' || c == '0' || c == ' ' || c == '+' || c == '-')
		return (1);
	return (-1);
}
