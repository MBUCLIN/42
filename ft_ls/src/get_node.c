#include "../includes/ft_ls.h"

t_all		*last_node(t_all *head)
{
	t_all		*tmp;

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
