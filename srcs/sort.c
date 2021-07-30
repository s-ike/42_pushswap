#include "push_swap.h"

void
	ft_sort(t_stacks *stacks)
{
	size_t	size;

	size = cdl_size(&stacks->a);
	if (size <= 1)
		return ;
	if (size <= 3)
		ft_sort_3(&stacks->a);
	else
		ft_sort_6(stacks);
}
