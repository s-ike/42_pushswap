#include "push_swap.h"

static void
	exec_2op(
		void f1(t_dlist *a, t_dlist *b),
		void f2(t_dlist *a, t_dlist *b),
		t_dlist *a,
		t_dlist *b)
{
	f1(a, b);
	f2(a, b);
}

void
	ft_sort_4(t_dlist *a)
{
	int		n[4];
	size_t	min_idx;

	n[0] = a->head->next->n;
	n[1] = a->head->next->next->n;
	n[2] = a->head->next->next->next->n;
	n[3] = a->head->next->next->next->next->n;
	min_idx = cdl_get_min_node_idx(a);
	if (min_idx == 1)
	{
		if (n[2] < n[3] && n[3] < n[1]) // 1,4,2,3
			exec_2op(ft_ss, ft_rr, a, NULL);
		else if (n[3] < n[1] && n[1] < n[2]) // 1,3,4,2
			exec_2op(ft_rrr, ft_ss, a, NULL);
	}
	else if (min_idx == 2)
	{
		if (n[0] < n[2] && n[2] < n[3]) // 2,1,3,4
			ft_ss(a, NULL);
		else if (n[3] < n[0] && n[0] < n[2]) // 3,1,4,2
		{
			exec_2op(ft_rr, ft_ss, a, NULL);
			ft_rr(a, NULL);
		}
	}
	else if (min_idx == 3)
	{
		if (n[0] < n[1] && n[1] < n[3]) // 2,3,1,4
		{
			exec_2op(ft_rrr, ft_rrr, a, NULL);
			exec_2op(ft_ss, ft_rr, a, NULL);
		}
		else if (n[1] < n[3] && n[3] < n[0]) // 4,2,1,3
			exec_2op(ft_rr, ft_ss, a, NULL);
	}
	else if (min_idx == 4)
	{
		if (n[2] < n[0] && n[0] < n[1]) // 3,4,2,1
		{
			exec_2op(ft_rrr, ft_rrr, a, NULL);
			ft_ss(a, NULL);
		}
		else if (n[1] < n[2] && n[2] < n[0]) // 4,2,3,1
		{
			exec_2op(ft_rrr, ft_ss, a, NULL);
			ft_rr(a, NULL);
		}
	}
}
