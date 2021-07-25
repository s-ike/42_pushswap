#include "circular_dlist.h"

int
	cdl_init_dlist(t_dlist *dlist)
{
	t_dnode	*dummy_node;

	dummy_node = (t_dnode *)ft_calloc(1, sizeof(t_dnode));
	if (!dummy_node)
		return (0);
	dlist->head = dummy_node;
	dlist->crnt = dummy_node;
	dummy_node->prev = dummy_node;
	dummy_node->next = dummy_node;
	return (1);
}
