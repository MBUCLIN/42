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
	while (tmp)
	{
		if (!(dir = opendir(tmp->name->path)))
		{
			perror(tmp->name->name);
			tmp = tmp->next;
		}
		if (!(tmp->son = read_dir(tmp, dir, option)))
			return (del_all(head));
		if (closedir(dir))
			return (del_all(head));
		dir = NULL;
		if (option & OPT_MR || !ft_strcmp(tmp->name->name, "."))
			ft_printf("%s:\n", tmp->name->path);
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
		if (check_dir(tmp, option))
		{
			if (option & OPT_MR || !ft_strcmp(tmp->name->name, "."))
				ft_printf("%s:\n", tmp->name->path);
			if (!(dir = opendir(tmp->name->path)))
				perror(tmp->name->name);
			else if  (!(tmp->son = read_dir(tmp, dir, option)))
				return (del_all(head));
			else if (closedir(dir))
				return (del_all(head));
			dir = NULL;
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
