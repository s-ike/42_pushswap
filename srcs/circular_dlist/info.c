#include "circular_dlist.h"

int
	cdl_is_empty(const t_dlist *dlist)
{
	return (dlist->head->next == dlist->head);
}

size_t
	cdl_size(const t_dlist *dlist)
{
	t_dnode	*ptr;
	size_t	cnt;

	cnt = 0;
	if (cdl_is_empty(dlist))
		return (cnt);
	ptr = dlist->head->next;
	while (ptr != dlist->head)
	{
		ptr = ptr->next;
		cnt++;
	}
	return (cnt);
}

int
	cdl_is_sorted(t_dnode *head, t_dnode *start, int compare(int x, int y))
{
	t_dnode	*ptr;

	ptr = start;
	while (ptr != head && ptr->next != head)
	{
		if (!compare(ptr->n, ptr->next->n))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int
	cdl_is_sorted_asc_in_range(t_dlist *dlist, int start_id, int end_id)
{
	t_dnode	*ptr;
	t_dnode	*prev;
	size_t	size;

	size = cdl_size(dlist);
	ptr = dlist->head->next;
	if (ptr == dlist->head)
		return (0);
	ptr = cdl_search(dlist, start_id, cdl_ncmp);
	prev = ptr->prev;
	if (prev == dlist->head)
		prev = prev->prev;
	while (size--)
	{
		if (ptr->id != start_id && prev->id + 1 != ptr->id)
			return (0);
		if (ptr->id == end_id)
			return (1);
		prev = ptr;
		ptr = ptr->next;
		if (ptr == dlist->head)
			ptr = ptr->next;
	}
	return (1);
}
