#include "push_swap.h"

static void
	rotate_a_in_range(t_dlist *a, int l, int r)
{
	t_dnode	*lp;
	t_dnode	*rp;
	int		start_r;

	lp = a->head->next->next;
	rp = a->head->prev;
	start_r = rp->id;
	while (lp->id != start_r)
	{
		if ((l <= lp->id && lp->id <= r) && (l <= rp->id && rp->id <= r))
		{
			if ((l <= lp->next->id && lp->next->id <= r)
			&& !(l <= rp->prev->id && rp->prev->id <= r))
				return (ft_rr(a, NULL));
			else
				return (ft_rrr(a, NULL));
		}
		else if (l <= lp->id && lp->id <= r)
			return (ft_rr(a, NULL));
		else if (l <= rp->id && rp->id <= r)
			return (ft_rrr(a, NULL));
		lp = lp->next;
		rp = rp->prev;
	}
	ft_rrr(a, NULL);
}

void
	ft_rotate_a_in_range(t_dlist *a, int l, int r)
{
	t_dnode	*lp;

	if (l < 0 || r < 0)
		return ;
	lp = a->head->next;
	if (l <= lp->id && lp->id <= r)
		return ;
	rotate_a_in_range(a, l, r);
}

static void
	rotate_b_until_find_id_or_more_in_range(t_dlist *b, int p, int l)
{
	t_dnode	*lp;
	t_dnode	*rp;
	int		start_r;

	lp = b->head->next->next;
	rp = b->head->prev;
	start_r = rp->id;
	while (lp->id != start_r)
	{
		if ((l <= lp->id && p <= lp->id) && (l <= rp->id && p <= rp->id))
		{
			if ((l <= lp->next->id && p <=lp->next->id)
			&& !(l <= rp->prev->id && p <= rp->prev->id))
				return (ft_rr(NULL, b));
			else
				return (ft_rrr(NULL, b));
		}
		else if (l <= lp->id && p <= lp->id)
			return (ft_rr(NULL, b));
		else if (l <= rp->id && p <= rp->id)
			return (ft_rrr(NULL, b));
		lp = lp->next;
		rp = rp->prev;
	}
	ft_rrr(NULL, b);
}

void
	ft_rotate_b_until_find_id_or_more_in_range(t_dlist *b, int p, int l, int r)
{
	t_dnode	*lp;

	if (l < 0 || p < 0 || r < p)
		return ;
	lp = b->head->next;
	if (l <= lp->id && p <= lp->id)
		return ;
	rotate_b_until_find_id_or_more_in_range(b, p, l);
}
