#include "../includes/ft_ls.h"

t_all		*read_dir(t_all *node, DIR *dir, int option)
{
	struct dirent	dirent;
	char			*path;
	t_all			*head;
	t_all			*tmp;


	while (dirent = readdir(dir))
	{
		if (!(path = ft_strdup(node->name->path)))
			return (del_all(head));
		if (!(path = ft_strjoindfree(path, ft_strdup(dirent.d_name))))
			return (del_all(head));
		if (!(tmp =\
			new_node_all(new_name(ft_strdup(dirent.d_name, path), option))))
			return (del_all(head));
		head = insert(head, tmp, option);
	}
}

t_all		*read_dir_arg(t_all *head, int option)
{
	DIR				*dir;
	t_all			*tmp;

	tmp = head;
	ft_putendl(tmp->name->path);
	while (tmp)
	{
		if (!(dir = opendir(tmp->name->name)))
			return (del_all(head));
		if (!(tmp->son = read_dir(tmp, dir, option)))
			return (del_all(head));
		if (!(print_dir(tmp->son, get_max_len(tmp->son))))
			return (del_all(head));
		del_all(tmp->son);
		tmp = tmp->next;
	}
	return (head);
}
