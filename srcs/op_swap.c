#include "push_swap.h"

static void
	sa_or_sb(t_dlist *dlist)
{
	int	tmp;

	tmp = dlist->head->next->n;
	dlist->head->next->n = dlist->head->next->next->n;
	dlist->head->next->next->n = tmp;
}

static void
	ss(t_dlist *a, t_dlist *b)
{
	sa_or_sb(a);
	sa_or_sb(b);
}

void
	ft_ss(t_dlist *a, t_dlist *b)
{
	if (b == NULL)
	{
		sa_or_sb(a);
		ft_putendl_fd("sa", STDOUT_FILENO);
	}
	else if (a == NULL)
	{
		sa_or_sb(b);
		ft_putendl_fd("sb", STDOUT_FILENO);
	}
	else
	{
		ss(a, b);
		ft_putendl_fd("ss", STDOUT_FILENO);
	}
}
