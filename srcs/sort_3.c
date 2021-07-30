#include "push_swap.h"

static void
	sort_2(t_dlist *a)
{
	int	x;
	int	y;

	x = a->head->next->n;
	y = a->head->next->next->n;
	if (y < x)
		ft_ss(a, NULL);
}

/*
if (y < x && x < z)      // 2,1,3
else if (z < y && y < x) // 3.2.1
else if (y < z && z < x) // 3,1,2
else if (x < z && z < y) // 1,3,2
else if (z < x && x < y) // 2,3,1
*/
static void
	sort_3(t_dlist *a)
{
	int	x;
	int	y;
	int	z;

	x = a->head->next->n;
	y = a->head->next->next->n;
	z = a->head->next->next->next->n;
	if (y < x && x < z)
		ft_ss(a, NULL);
	else if (z < y && y < x)
	{
		ft_ss(a, NULL);
		ft_rrr(a, NULL);
	}
	else if (y < z && z < x)
		ft_rr(a, NULL);
	else if (x < z && z < y)
	{
		ft_ss(a, NULL);
		ft_rr(a, NULL);
	}
	else if (z < x && x < y)
		ft_rrr(a, NULL);
}

void
	ft_sort_3(t_dlist *a)
{
	size_t	size;

	size = cdl_size(a);
	if (size == 2)
		sort_2(a);
	else
		sort_3(a);
}
