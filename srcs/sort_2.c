#include "push_swap.h"

void
	ft_sort_2(t_dlist *a)
{
	int	x;
	int	y;

	x = a->head->next->n;
	y = a->head->next->next->n;
	if (y < x)
		ft_ss(a, NULL);
}
