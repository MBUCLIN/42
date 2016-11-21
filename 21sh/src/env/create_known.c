/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_known.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:41:22 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/21 15:00:27 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static void		create_shlvl(char *shlvl)
{
	char		*value;

	if ((value = ft_strdup("1")) == NULL)
	{
		sherror("21sh", ERRMALLOC, NULL);
		exit(-1);
	}
	ft_setenv(shlvl, value);
	free(value);
}

static void		create_pwd(char *pwd)
{
	char		*value;

	if ((value = getcwd(NULL, 0)) == NULL)
	{
		sherror("21sh", ERRMALLOC, NULL);
		exit(-1);
	}
	ft_setenv(pwd, value);
	free(value);
}

static char		*read_path_file(int fd)
{
	char		buf[BUF_SIZE + 1];
	int			ret;
	char		*pathes;

	ft_memset(buf, 0, BUF_SIZE + 1);
	pathes = NULL;
	while ((ret = read(fd, buf, BUF_SIZE)) >= 0)
	{
		if ((pathes = ft_strjoinfree(pathes, buf)) == NULL)
		{
			sherror("21sh", ERRMALLOC, NULL);
			exit(-1);
		}
		if (ret == 0)
			break ;
	}
	if ((pathes = ft_strsubfree(pathes, 0, ft_strlen(pathes) - 1)) == NULL)
	{
		sherror("21sh", ERRMALLOC, NULL);
		exit(-1);
	}
	pathes = ft_strcrpl(pathes, '\n', ':');
	return (pathes);
}

static char		*open_path_file(char *filepath)
{
	int		fd;
	char	*pathes;

	if (access(filepath, R_OK) == -1)
	{
		sherror("21sh", ERRPATHPERM, filepath);
		return (NULL);
	}
	if ((fd = open(filepath, O_RDONLY)) == -1)
		return (NULL);
	pathes = read_path_file(fd);
	return (pathes);
}

static void		create_path(char *path)
{
	char		*value;

	if ((value = open_path_file("/private/etc/paths")) == NULL)
		return ;
	ft_setenv(path, value);
	free(value);
}
void			create_known(void)
{
	create_shlvl(FTSHLVL);
	create_pwd(FTPWD);
	create_path(FTPATH);
}
