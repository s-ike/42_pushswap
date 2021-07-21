#include "push_swap.h"

int
	ft_push(t_dlist *dlist, int n)
{
	return (cdl_add_front_dlist(dlist, n));
}

static int
	comp(int x, int y)
{
	return (x - y);
}

int
	ft_append_stack_while_check_dup(t_dlist *dlist, int n)
{
	if (cdl_search(dlist, n, comp) != NULL)
		return (0);
	return (cdl_add_back_dlist(dlist, n));
}

int
	ft_init_stack(t_dlist *dlist)
{
	return (cdl_init_dlist(dlist));
}

void
	ft_terminate_stack(t_dlist *dlist)
{
	cdl_terminate(dlist);
	return ;
}
