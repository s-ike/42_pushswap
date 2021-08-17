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
	ft_ra_or_rr(t_stacks *stacks, int target)
{
	if (stacks->b.head->next->id == target)
		return (ft_rr(&stacks->a, NULL));
	else if (2 < cdl_size(&stacks->b) && stacks->b.head->prev->id == target)
	{
		ft_rr(&stacks->a, NULL);
		return (ft_rrr(NULL, &stacks->b));
	}
	else if (1 < cdl_size(&stacks->b))
		return (ft_rr(&stacks->a, &stacks->b));
}

char
	*ft_get_rotate_op(t_dlist *dlist, size_t target_node_idx, char stack)
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
			return (OP_RRA);
		return (OP_RRB);
	}
	if (stack == 'a')
		return (OP_RA);
	return (OP_RB);
}

void
	ft_rotate_by_op(t_stacks *stacks, const char *op)
{
	if (!ft_strcmp(op, OP_RA))
		ft_rr(&stacks->a, NULL);
	else if (!ft_strcmp(op, OP_RB))
		ft_rr(NULL, &stacks->b);
	else if (!ft_strcmp(op, OP_RRA))
		ft_rrr(&stacks->a, NULL);
	else if (!ft_strcmp(op, OP_RRB))
		ft_rrr(NULL, &stacks->b);
	else if (!ft_strcmp(op, OP_RR))
		ft_rr(&stacks->a, &stacks->b);
	else if (!ft_strcmp(op, OP_RRR))
		ft_rrr(&stacks->a, &stacks->b);
}

void
	ft_rotate(t_stacks *stacks, size_t target_node_idx, char stack_name)
{
	char	*op;

	if (stack_name == 'a')
		op = ft_get_rotate_op(&stacks->a, target_node_idx, stack_name);
	else
		op = ft_get_rotate_op(&stacks->b, target_node_idx, stack_name);
	ft_rotate_by_op(stacks, op);
}
