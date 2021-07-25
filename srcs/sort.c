#include "push_swap.h"

void
	ft_sort(t_dlist *a)
{
	size_t	size;

	size = cdl_size(a);
	if (size <= 1)
		return ;
	if (size == 2)
		ft_sort_2(a);
	else if (size == 3)
		ft_sort_3(a);
	else
		ft_sort_6(a);
}
