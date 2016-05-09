#include "../includes/ft_ls.h"

t_all		*read_dir(t_all *node, DIR *dir, int option)
{
	struct dirent		*dirent;
	char			*path;
	t_all			*head;
	t_all			*tmp;

	head = NULL;
	while ((dirent = readdir(dir)))
	{
		if (!(path = create_path(node->name->path, dirent->d_name)))
			return (del_all(head));
		if (!(tmp =\
			new_node_all(new_name(dirent->d_name, path), option)))
			return (del_all(head));
		free(path);
		path = NULL;
		if (!(head))
			head = tmp;
		head = import(head, tmp, option);
	}
	return (head);
}

t_all		*read_dir_arg(t_all *head, int option)
{
	DIR				*dir;
	t_all			*tmp;

	tmp = head;
	ft_printf("%d : leaks\n", sizeof(t_all));
	while (tmp)
	{
		if (!(dir = opendir(tmp->name->path)))
			return (del_all(head));
		if (!(tmp->son = read_dir(tmp, dir, option)))
			return (del_all(head));
		if (closedir(dir))
			return (del_all(head));
		dir = NULL;
		ft_printf("%s:\n", tmp->name->path);
		ft_printf("total %d\n", total_size(tmp->son, option));
		if (!(tmp->son = print_dir(tmp->son, get_len_max(tmp->son), option)))
			return (del_all(head));
		ft_putendl("");
		tmp->son = del_all(tmp->son);
		tmp = tmp->next;
	}
	return (head);
}

t_all		*recursive(t_all *head, int option)
{
	DIR			*dir;
	t_all		*tmp;

	tmp = head;
	dir = NULL;
	while (tmp)
	{
		if ((tmp->info->mode & 040000) && (ft_strcmp(tmp->name->name, ".") &&\
			ft_strcmp(tmp->name->name, "..")))
		{
			if (!(dir = opendir(tmp->name->path)))
				return (del_all(head));
			if (!(tmp->son = read_dir(tmp, dir, option)))
				return (del_all(head));
			if (closedir(dir))
				return (del_all(head));
			dir = NULL;
			ft_printf("%s:\n", tmp->name->path);
			ft_printf("total %d\n", total_size(tmp->son, option));
			if (!(tmp->son =\
				print_dir(tmp->son, get_len_max(tmp->son), option)))
				return (del_all(head));
			ft_putendl("");
			if (!(tmp->son = recursive(tmp->son, option)))
				return (del_all(head));
			tmp->son = del_all(tmp->son);
		}
		tmp = tmp->next;
	}
	return (head);
}
