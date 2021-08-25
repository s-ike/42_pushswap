/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_7_pa2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 23:18:09 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/25 23:24:40 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	cnt_rotate_b(t_dnode **ptr, int *start_id, size_t *cnt, int target_id)
{
	int	flag[LR];

	flag[L] = 0;
	flag[R] = 0;
	while (ptr[L]->id != start_id[R] && ptr[R]->id != start_id[L])
	{
		if (ptr[L]->id != start_id[R] && ptr[L]->id != target_id)
		{
			ptr[L] = ptr[L]->next;
			cnt[L]++;
		}
		else
			flag[L] = 1;
		if (ptr[R]->id != start_id[L] && ptr[R]->id != target_id)
		{
			ptr[R] = ptr[R]->prev;
			cnt[R]++;
		}
		else
			flag[R] = 1;
		if ((flag[L] && flag[R]) || cnt[L] < cnt[R])
			break ;
	}
}

static char
	*rotate_b(t_dlist *b, int target_id)
{
	t_dnode	*ptr[LR];
	int		start_id[LR];
	size_t	cnt[LR];

	ptr[L] = b->head->next;
	ptr[R] = b->head->prev;
	start_id[L] = ptr[L]->id;
	start_id[R] = ptr[R]->id;
	cnt[L] = 0;
	cnt[R] = 0;
	cnt_rotate_b(ptr, start_id, cnt, target_id);
	if (cnt[L] < cnt[R])
		return (OP_RB);
	else if (cnt[R] < cnt[L] / 2)
		return (OP_RRB);
	else
		return (OP_RB);
}

static void
	pa_and_rotate_a(t_pushswap *ps, int *id)
{
	t_dlist	*a;
	t_dlist	*b;

	a = &ps->stacks.a;
	b = &ps->stacks.b;
	ft_pa(a, b, ps);
	(id[L])++;
	if (b->head->next->id == id[L])
		ft_rr(a, NULL, ps);
	else if (!ft_strcmp(rotate_b(b, id[L]), OP_RB))
		ft_rr(a, b, ps);
	else
		ft_rr(a, NULL, ps);
}

void
	ft_pa_and_rotate_b_loop(
		t_pushswap *ps, int *not_targets, t_bool not_targets_flag, int *id)
{
	t_dnode	*ptr;

	ptr = ps->stacks.b.head->next;
	while (ptr != ps->stacks.b.head
		&& ((not_targets_flag == FALSE && *not_targets)
			|| not_targets_flag == TRUE))
	{
		if (ptr->id < id[R] && ptr->id == id[L])
			pa_and_rotate_a(ps, id);
		else if (id[R] <= ptr->id)
		{
			ft_pa(&ps->stacks.a, &ps->stacks.b, ps);
			(*not_targets)--;
		}
		else if (ps->stacks.b.head->prev->id == id[L])
			ft_rrr(NULL, &ps->stacks.b, ps);
		else
			ft_rotate_by_op(ps, rotate_b(&ps->stacks.b, id[L]));
		ptr = ps->stacks.b.head->next;
	}
}
