#include "push_swap.h"

int
	ft_pa(t_dlist *a, t_dlist *b)
{
	int	ret;

	ret = cdl_add_front_dlist(a, b->head->next->n, b->head->next->id);
	if (ret)
	{
		ft_putendl_fd("pa", STDOUT_FILENO);
		cdl_remove_front(b);
	}
	return (ret);
}

int
	ft_pb(t_dlist *a, t_dlist *b)
{
	int	ret;

	ret = cdl_add_front_dlist(b, a->head->next->n, a->head->next->id);
	if (ret)
	{
		ft_putendl_fd("pb", STDOUT_FILENO);
		cdl_remove_front(a);
	}
	return (ret);
}
