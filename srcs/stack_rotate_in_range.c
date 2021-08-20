/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_in_range.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:10:16 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/20 11:22:37 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	rotate_b_until_find_id_in_range(t_dlist *b, int p, int l)
{
	t_dnode	*lp;
	t_dnode	*rp;
	int		start_rp_id;
	int		start_lp_id;
	size_t	lp_cnt;
	size_t	rp_cnt;
	int		lp_flag;
	int		rp_flag;

	(void)p;
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
		if (lp->id != start_rp_id && lp->id != l)
		{
			lp = lp->next;
			lp_cnt++;
		}
		else
			lp_flag = 1;
		if (rp->id != start_lp_id && rp->id != l)
		{
			rp = rp->prev;
			rp_cnt++;
		}
		else
			rp_flag = 1;
		if ((lp_flag && rp_flag) || lp_cnt < rp_cnt)
			break ;
	}
	if (lp_cnt < rp_cnt)
		ft_rr(NULL, b);
	else if (rp_cnt < lp_cnt / 2)
		ft_rrr(NULL, b);
	else
		ft_rr(NULL, b);
}

void
	ft_rotate_b_until_find_id_in_range(t_dlist *b, int p, int l, int r)
{
	t_dnode	*lp;

	if (l < 0 || p < 0 || r < p)
		return ;
	lp = b->head->next;
	if (l <= lp->id && lp->id == l)
		return ;
	rotate_b_until_find_id_in_range(b, p, l);
}
