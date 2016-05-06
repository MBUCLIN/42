#include "../includes/ft_ls.h"

t_all		*insert(t_all *head, t_all *new, t_all *node)
{
	t_all		*tmp;

	tmp = head;
	if (tmp == node)
	{
		new->next = head;
		return (new);
	}
	while (tmp->next != node)
		tmp = tmp->next;
	tmp->next = new;
	new->next = node;
	return (head);
}

t_all		*import_from_else(t_all *head, t_all *new, t_all *node)
{
	int		ntt;
	int		ntn;

	ntn = new->info->ntime;
	ntt = node->info->ntime;
	if (ntn > ntt)
		return (insert(head, new, node));
	else if (ntn == ntt)
	{
		if (!ft_islexisort(new->name->name, node->name->name))
			return (insert(head, new, node));
	}
	if (!node->next)
		node->next = new;
	return (head);
}

t_all		*import_from_time(t_all *head, t_all *node)
{
	t_all		*tmp;
	int			tt;
	int			tn;

	tmp = head;
	if (head == node)
		return (head);
	while (tmp)
	{
		tn = node->info->time;
		tt = tmp->info->time;
		if (tn > tt)
		{
			return (insert(head, node, tmp));
		}
		else if (tn == tt)
			return (import_from_else(head, node, tmp));
		tmp = tmp->next;
	}
	tmp = last_node(head);
	tmp->next = node;
	node->next = NULL;
	return (head);
}

t_all		*import(t_all *head, t_all *node, int option)
{
	t_all		*tmp;

	if (option & OPT_T)
		return (import_from_time(head, node));
	tmp = head;
	while (tmp)
	{
		if (!(ft_islexisort(node->name->name, tmp->name->name)))
		{
			head = insert(head, node, tmp);
			return (head);
		}
		tmp = tmp->next;
	}
	tmp = last_node(head);
	tmp->next = node;
	node->next = NULL;
	return (head);
}
