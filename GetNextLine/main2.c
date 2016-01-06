#include "Get_Next_Line/get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	int		fd_2;
	int		gob;
	char	*line;
	int		i;
	int		gob2;

	i = 0;
	if (ac < 2)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	if ((fd_2 = open(av[2], O_RDONLY)) == -1)
		return (0);
	while (i < 125)
	{
		if ((gob = get_next_line(fd, &line)) > 0)
		{
			ft_putstr(line);
			ft_putstr(", ");
			free(line);
			line = NULL;
		}
		else
			return (0);
		if ((gob2 = get_next_line(fd_2, &line)) > 0)
		{
			ft_putstr(line);
			free(line);
			line = NULL;
		}
		ft_putendl("");
		i++;
	}
	return (1);
}
