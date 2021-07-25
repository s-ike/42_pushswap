#include "circular_dlist.h"

static void
	set_dnode(t_dnode *node, int n, t_dnode *prev, t_dnode *next)
{
	node->n = n;
	node->prev = prev;
	node->next = next;
}

static int
	insert_after(t_dlist *dlist, t_dnode *prev, int n)
{
	t_dnode	*new_node;
	t_dnode	*next;

	new_node = (t_dnode *)ft_calloc(1, sizeof(t_dnode));
	if (!new_node)
		return (0);
	next = prev->next;
	prev->next->prev = new_node;
	prev->next = new_node;
	set_dnode(new_node, n, prev, next);
	dlist->crnt = new_node;
	return (1);
}

int
	cdl_add_front_dlist(t_dlist *dlist, int n)
{
	return (insert_after(dlist, dlist->head, n));
}

int
	cdl_add_back_dlist(t_dlist *dlist, int n)
{
	return (insert_after(dlist, dlist->head->prev, n));
}
