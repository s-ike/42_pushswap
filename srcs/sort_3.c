#include "push_swap.h"

void
	ft_sort_3(t_dlist *a)
{
	int	x;
	int	y;
	int	z;

	x = a->head->next->n;
	y = a->head->next->next->n;
	z = a->head->next->next->next->n;
	if (y < x && x < z) // 2,1,3
		ft_ss(a, NULL);
	else if (z < y && y < x) // 3.2.1
	{
		ft_ss(a, NULL);
		ft_rrr(a, NULL);
	}
	else if (y < z && z < x) // 3,1,2
		ft_rr(a, NULL);
	else if (x < z && z < y) // 1,3,2
	{
		ft_ss(a, NULL);
		ft_rr(a, NULL);
	}
	else if (z < x && x < y) // 2,3,1
		ft_rrr(a, NULL);
}
