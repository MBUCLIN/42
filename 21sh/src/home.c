/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:57:34 by mbuclin           #+#    #+#             */
/*   Updated: 2016/12/01 14:07:40 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

static int		check_time(char *path, t_list *d_name, long t)
{
	struct stat		buf;
	char			*fullpath;
	int				sta;

	if (d_name == NULL)
		return (t);
	if ((fullpath = ft_strjoin(path, d_name->content)) == NULL)
		ft_exitshell("21sh", ERRMALLOC, NULL);
	if ((sta = stat(fullpath, &buf)) == -1)
		t = check_time(path, d_name->next, t);
	if (sta != -1 && t < buf.st_mtimespec.tv_sec)
		t = buf.st_mtimespec.tv_sec;
	t = check_time(path, d_name->next, t);
	free(fullpath);
	ft_printf("%ld : t\n", t);
	return (t);
}

static char		*get_homepath(long t, t_list *d_name, char *path)
{
	char			*fullpath;
	struct stat		buf;
	t_list			*tmp;

	tmp = d_name;
	while (tmp != NULL)
	{
		if ((fullpath = ft_strjoin(path, tmp->content)) == NULL)
			ft_exitshell("21sh", ERRMALLOC, NULL);
		if (stat(fullpath, &buf) != -1)
		{
			if (buf.st_mtimespec.tv_sec == t)
				return (fullpath);
		}
		tmp = tmp->next;
		free(fullpath);
	}
	return (NULL);
}

static char		*read_usersdir(DIR *users, char *path)
{
	struct dirent		*in_dir;
	t_list				*inner;
	t_list				*tmp;
	long				t;

	inner = NULL;
	while ((in_dir = readdir(users)) != NULL)
	{
		tmp = NULL;
		if ((tmp = ft_lstnew(in_dir->d_name,\
						in_dir->d_namlen)) == NULL)
			ft_exitshell("21sh", ERRMALLOC, NULL);
		tmp->next = inner;
		inner = tmp;
	}
	t = check_time(path, inner, -1);
	if (t == -1)
		ft_putendl("T == -1");
	else
		ft_putendl("T has value");
	return (get_homepath(t, inner, path));
}

static char		*search_homedir(char *path)
{
	DIR				*dir_open;

	if ((dir_open = opendir(path)) == NULL)
	{
		ft_putendl("OPENDIR NULL");
		return (NULL);
	}
	return (read_usersdir(dir_open, path));
}

char			*ft_gethome(void)
{
	static char		*home = NULL;

	if (home == NULL)
		if ((home = search_homedir("/Users/")) == NULL)
		{
			ft_printf("|%s| : home\n", home);
			return (NULL);
		}
	ft_printf("|%s| : home\n", home);
	return (home);
}
