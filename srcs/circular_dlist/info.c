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
