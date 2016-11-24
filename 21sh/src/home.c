/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:57:34 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/24 15:08:23 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

static char		*check_time(char *path, t_list *name, long t)
{
	struct stat		buf;
	char			*fullpath;
	char			*ret;

	ret = NULL;
	if (name == NULL)
		return (ret);
	if ((fullpath = ft_strjoin(path, name->content)) == NULL)
		ft_exitshell("21sh", ERRMALLOC, NULL);
	if (stat(fullpath, &buf) == -1)
		ret = check_time(path, name->next, t);
	if (t < buf.st_mtimespec.tv_sec)
		t = buf.st_mtimespec.tv_sec;
	ret = check_time(path, name->next, t);
	if (t == buf.st_mtimespec.tv_sec)
		return (fullpath);
	free(fullpath);
	return (ret);
}

static char		*read_usersdir(DIR *users, char *path)
{
	struct dirent		*in_dir;
	t_list				*inner;
	t_list				*tmp;

	inner = NULL;
	while ((in_dir = readdir(users)) == NULL)
	{
		tmp = NULL;
		if ((tmp = ft_lstnew(in_dir->d_name,\
						ft_strlen(in_dir->d_name))) == NULL)
			ft_exitshell("21sh", ERRMALLOC, NULL);
		tmp->next = inner;
		inner = tmp;
	}
	return (check_time(path, inner, 0));
}

static char		*search_homedir(char *path)
{
	DIR				*dir_open;

	if ((dir_open = opendir(path)) == NULL)
		return (NULL);
	return (read_usersdir(dir_open, path));
}

char			*ft_gethome(void)
{
	static char		*home = NULL;

	if (home == NULL)
		if ((home = search_homedir("/Users")) == NULL)
			return (NULL);
	return (home);
}
