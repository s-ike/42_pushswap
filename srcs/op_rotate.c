#include "push_swap.h"

static void
	ra_or_rb(t_dlist *dlist)
{
	int	next_n;

	next_n = dlist->head->next->n;
	dlist->head->n = next_n;
	dlist->head->next->n = 0;
	dlist->head = dlist->head->next;
}

static void
	rr(t_dlist *a, t_dlist *b)
{
	ra_or_rb(a);
	ra_or_rb(b);
}

void
	ft_rr(t_dlist *a, t_dlist *b)
{
	if (b == NULL)
	{
		ra_or_rb(a);
		ft_putendl_fd("ra", STDOUT_FILENO);
	}
	else if (a == NULL)
	{
		ra_or_rb(b);
		ft_putendl_fd("rb", STDOUT_FILENO);
	}
	else
	{
		rr(a, b);
		ft_putendl_fd("rr", STDOUT_FILENO);
	}
}
