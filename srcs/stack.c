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
	ft_rotate_a(t_dlist *a, size_t target_node_idx)
{
	size_t	proximity;
	size_t	size;

	size = cdl_size(a);
	proximity = size / 2;
	if (proximity < (size + 1) / 2)
		proximity = (size + 1) / 2;
	if (proximity < target_node_idx)
		ft_rrr(a, NULL);
	else
		ft_rr(a, NULL);
}
