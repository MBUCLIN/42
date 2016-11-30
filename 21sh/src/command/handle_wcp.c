/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wcp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:54:42 by mbuclin           #+#    #+#             */
/*   Updated: 2016/11/28 13:41:47 by mbuclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static char			*set_word(char *word, int set)
{
	static char		*saved = NULL;

	if (ft_strlen(word) < 1 && set)
	{
		if (saved != NULL)
			free(saved);
		saved = NULL;
	}
	if (set)
	{
		saved = ft_strdup(word);
		free(word);
	}
	return (saved);
}

static char			*get_word(void)
{
	char	*word;

	word = set_word(NULL, 0);
	return (word);
}

static void			cut_word(t_command **cmd)
{
	char		*cuted;
	int			len;
	int			i;

	len = 0;
	i = 0;
	cuted = NULL;
	len = moove_wrgt(cmd);
	if (len == 0)
		return ;
	(*cmd)->pos -= len;
	if ((cuted = ft_strsub((*cmd)->command, (*cmd)->pos, len + 1)) == NULL)
		ft_exitshell("21sh", ERRMALLOC, NULL);
	while (i <= len)
	{
		right_moove(*cmd, 0);
		(*cmd)->pos++;
		i++;
	}
	i = -1;
	while (++i <= len)
		handle_del(cmd);
	set_word(cuted, 1);
}

static void			paste_word()
{
	char		*pasted;

	pasted = NULL;
	pasted = get_word();
	if (pasted != NULL)
		handle_normal(pasted);
}

void				handle_wcp(char *buf, t_command **cmd)
{
	if (buf[0] == 14)
		cut_word(cmd);
	else
	{
		paste_word();
	}
	set_command(cmd);
}
