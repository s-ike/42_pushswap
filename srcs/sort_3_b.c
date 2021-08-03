#include "push_swap.h"

static void
	sort_2(t_dlist *b)
{
	int	x;
	int	y;

	x = b->head->next->n;
	y = b->head->next->next->n;
	if (x < y)
		ft_ss(NULL, b);
}

/*
if (y < x && x < z)      // 2,1,3
else if (z < y && y < x) // 1.2.3
else if (y < z && z < x) // 3,1,2
else if (x < z && z < y) // 1,3,2
else if (z < x && x < y) // 2,3,1
*/
static void
	sort_3(t_dlist *b)
{
	int	x;
	int	y;
	int	z;

	x = b->head->next->n;
	y = b->head->next->next->n;
	z = b->head->next->next->next->n;
	if (y < x && x < z)
		ft_rrr(NULL, b);
	else if (x < y && y < z)
	{
		ft_ss(NULL, b);
		ft_rrr(NULL, b);
	}
	else if (y < z && z < x)
	{
		ft_rrr(NULL, b);
		ft_ss(NULL, b);
	}
	else if (x < z && z < y)
		ft_rr(NULL, b);
	else if (z < x && x < y)
		ft_ss(NULL, b);
}

void
	ft_sort_3_b(t_dlist *b)
{
	size_t	size;

	size = cdl_size(b);
	if (size == 2)
		sort_2(b);
	else
		sort_3(b);
}
