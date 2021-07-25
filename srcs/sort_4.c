#include "push_swap.h"

static void
	sort_4_minidx1(t_dlist *a, int *n)
{
	if (n[2] < n[3] && n[3] < n[1]) // 1,4,2,3
	{
		ft_ss(a, NULL);
		ft_rr(a, NULL);
	}
	else if (n[3] < n[1] && n[1] < n[2]) // 1,3,4,2
	{
		ft_rrr(a, NULL);
		ft_ss(a, NULL);
	}
}

static void
	sort_4_minidx2(t_dlist *a, int *n)
{
	if (n[0] < n[2] && n[2] < n[3]) // 2,1,3,4
		ft_ss(a, NULL);
	else if (n[3] < n[0] && n[0] < n[2]) // 3,1,4,2
	{
		ft_rr(a, NULL);
		ft_ss(a, NULL);
		ft_rr(a, NULL);
	}
}

static void
	sort_4_minidx3(t_dlist *a, int *n)
{
	if (n[0] < n[1] && n[1] < n[3]) // 2,3,1,4
	{
		ft_rrr(a, NULL);
		ft_rrr(a, NULL);
		ft_ss(a, NULL);
		ft_rr(a, NULL);
	}
	else if (n[1] < n[3] && n[3] < n[0]) // 4,2,1,3
	{
		ft_rr(a, NULL);
		ft_ss(a, NULL);
	}
}

static void
	sort_4_minidx4(t_dlist *a, int *n)
{
	if (n[2] < n[0] && n[0] < n[1]) // 3,4,2,1
	{
		ft_rrr(a, NULL);
		ft_rrr(a, NULL);
		ft_ss(a, NULL);
	}
	else if (n[1] < n[2] && n[2] < n[0]) // 4,2,3,1
	{
		ft_rrr(a, NULL);
		ft_ss(a, NULL);
		ft_rr(a, NULL);
	}
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
		sort_4_minidx1(a, n);
	else if (min_idx == 2)
		sort_4_minidx2(a, n);
	else if (min_idx == 3)
		sort_4_minidx3(a, n);
	else if (min_idx == 4)
		sort_4_minidx4(a, n);
}
