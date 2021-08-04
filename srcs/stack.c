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

void
	ft_rotate_a_less_than_p_in_range(t_dlist *a, int p, int l, int r)
{
	t_dnode	*lp;
	t_dnode	*rp;

	if (l < 0 || p < 0 || r < p)
		return ;
	lp = a->head->next;
	if (l <= lp->id && lp->id < p)
		return ;
	lp = lp->next;
	rp = a->head->prev;
	while (lp != rp)
	{
		if ((l <= lp->id && lp->id < p) && (l <= rp->id && rp->id < p))
		{
			if ((l <= lp->next->id && lp->next->id < p)
			&& !(l <= rp->next->id && lp->next->id < p))
				return (ft_rr(a, NULL));
			else
				return (ft_rrr(a, NULL));
		}
		else if (l <= lp->id && lp->id < p)
			return (ft_rr(a, NULL));
		else if (l <= rp->id && rp->id < p)
			return (ft_rrr(a, NULL));
		lp = lp->next;
		rp = rp->prev;
	}
	ft_rrr(a, NULL);
}
