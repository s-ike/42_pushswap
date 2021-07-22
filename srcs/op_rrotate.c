#include "push_swap.h"

static void
	rra_or_rrb(t_dlist *dlist)
{
	int	prev_n;

	prev_n = dlist->head->prev->n;
	dlist->head->n = prev_n;
	dlist->head->prev->n = 0;
	dlist->head = dlist->head->prev;
}

static void
	rrr(t_dlist *a, t_dlist *b)
{
	rra_or_rrb(a);
	rra_or_rrb(b);
}

void
	ft_rrr(t_dlist *a, t_dlist *b)
{
	if (b == NULL)
	{
		rra_or_rrb(a);
		ft_putendl_fd("rra", STDOUT_FILENO);
	}
	else if (a == NULL)
	{
		rra_or_rrb(b);
		ft_putendl_fd("rrb", STDOUT_FILENO);
	}
	else
	{
		rrr(a, b);
		ft_putendl_fd("rrr", STDOUT_FILENO);
	}
}
