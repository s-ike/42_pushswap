#include "push_swap.h"

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

void
	ft_rotate(t_dlist *dlist, size_t target_node_idx, char stack)
{
	size_t	proximity;
	size_t	size;

	size = cdl_size(dlist);
	proximity = size / 2;
	if (proximity < (size + 1) / 2)
		proximity = (size + 1) / 2;
	if (proximity < target_node_idx)
	{
		if (stack == 'a')
			ft_rrr(dlist, NULL);
		else
			ft_rrr(NULL, dlist);
	}
	else
	{
		if (stack == 'a')
			ft_rr(dlist, NULL);
		else
			ft_rr(NULL, dlist);
	}
}
