#include "circular_dlist.h"

t_dnode
	*cdl_get_node_by_id(t_dlist *dlist, int id)
{
	t_dnode	*ptr;


	ptr = dlist->head->next;
	while (ptr != dlist->head)
	{
		if (ptr->id == id)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

t_dnode
	*cdl_get_node_by_idx(t_dlist *dlist, size_t idx)
{
	t_dnode	*ptr;
	size_t	cnt;

	ptr = dlist->head->next;
	cnt = 0;
	while (ptr != dlist->head)
	{
		if (++cnt == idx)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}

t_dnode
	*cdl_search(t_dlist *dlist, int id, int compare(int x, int y))
{
	t_dnode	*ptr;

	ptr = dlist->head->next;
	while (ptr != dlist->head)
	{
		if (compare(ptr->id, id) == 0)
		{
			dlist->crnt = ptr;
			return (ptr);
		}
		ptr = ptr->next;
	}
	return (NULL);
}

t_dnode
	*cdl_get_max_node(t_dlist *dlist)
{
	int		max;
	t_dnode	*max_ptr;
	t_dnode	*ptr;

	max_ptr = NULL;
	if (cdl_is_empty(dlist))
		return (max_ptr);
	max = -__INT_MAX__ - 1;
	ptr = dlist->head->next;
	while (ptr != dlist->head)
	{
		if (max < ptr->n)
		{
			max = ptr->n;
			max_ptr = ptr;
		}
		ptr = ptr->next;
	}
	return (max_ptr);
}

t_dnode
	*cdl_get_min_node(t_dlist *dlist)
{
	int		min;
	t_dnode	*min_ptr;
	t_dnode	*ptr;

	min_ptr = NULL;
	if (cdl_is_empty(dlist))
		return (min_ptr);
	min = __INT_MAX__;
	ptr = dlist->head->next;
	while (ptr != dlist->head)
	{
		if (ptr->n < min)
		{
			min = ptr->n;
			min_ptr = ptr;
		}
		ptr = ptr->next;
	}
	return (min_ptr);
}
