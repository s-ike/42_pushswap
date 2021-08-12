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

// lpから何個目で対象に行き着くか、rpから何個目で対象に行き着くか、比較
// rp_cnt < lp_cnt / 2だったらrrbする
static void
	rotate_b_until_find_id_or_more_in_range(t_dlist *b, int p, int l)
{
	t_dnode	*lp;
	t_dnode	*rp;
	int		start_rp_id;
	int		start_lp_id;
	size_t	lp_cnt;
	size_t	rp_cnt;
	int		lp_flag;
	int		rp_flag;

	lp = b->head->next;
	rp = b->head->prev;
	start_rp_id = rp->id;
	start_lp_id = lp->id;
	lp_cnt = 0;
	rp_cnt = 0;
	lp_flag = 0;
	rp_flag = 0;
	while (lp->id != start_rp_id && rp->id != start_lp_id)
	{
		if (lp->id != start_rp_id && !(l <= lp->id && p <= lp->id))
		{
			lp = lp->next;
			lp_cnt++;
		}
		else
			lp_flag = 1;
		if (rp->id != start_lp_id && !(l <= rp->id && p <= rp->id))
		{
			rp = rp->prev;
			rp_cnt++;
		}
		else
			rp_flag = 1;
		if (lp_flag && rp_flag)
			break ;
	}
	if (rp_cnt < lp_cnt / 2)
		ft_rrr(NULL, b);
	else
		ft_rr(NULL, b);
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
