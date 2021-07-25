#include "push_swap.h"

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
	ft_init_stacks(t_stacks *stacks)
{
	if (cdl_init_dlist(&stacks->a))
		return (cdl_init_dlist(&stacks->b));
	return (0);
}

void
	ft_terminate_stacks(t_stacks *stacks)
{
	cdl_terminate(&stacks->a);
	cdl_terminate(&stacks->b);
	return ;
}
