#include "push_swap.h"

int
	ft_pa(t_dlist *a, t_dlist *b, int n)
{
	int	ret;

	ret = cdl_add_front_dlist(a, n);
	if (ret)
	{
		ft_putendl_fd("pa", STDOUT_FILENO);
		cdl_remove_front(b);
	}
	return (ret);
}

int
	ft_pb(t_dlist *a, t_dlist *b, int n)
{
	int	ret;

	ret = cdl_add_front_dlist(b, n);
	if (ret)
	{
		ft_putendl_fd("pb", STDOUT_FILENO);
		cdl_remove_front(a);
	}
	return (ret);
}
