/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_7_pb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 16:32:56 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/27 02:34:17 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	skip_target(t_stacks *stacks, int *l, int *targets, t_bool *flag)
{
	t_dnode	*a_top;
	t_dnode	*a_btm;

	a_top = stacks->a.head->next;
	a_btm = stacks->a.head->prev;
	if ((a_top->id == *l && (a_btm->id == *l - 1 || *flag == FALSE))
		|| (a_btm->id == *l && (a_btm->prev->id == *l - 1 || *flag == FALSE)))
	{
		(*l)++;
		(*targets)--;
		*flag = TRUE;
	}
}

static int
	sa(t_pushswap *ps, int r)
{
	t_dnode	*a_top;
	t_dnode	*a_btm;

	a_top = ps->stacks.a.head->next;
	a_btm = ps->stacks.a.head->prev;
	if (a_top->id <= r
		&& a_top->next->id <= r
		&& a_top->next != ps->stacks.a.head
		&& a_top->next->id == a_btm->id + 1
		&& a_top->id == a_top->next->id + 1)
	{
		ft_ss(&ps->stacks.a, NULL, ps, TRUE);
		return (1);
	}
	return (0);
}

static void
	rb(t_pushswap *ps, int l, int r)
{
	t_dnode	*b_top;

	b_top = ps->stacks.b.head->next;
	if (2 <= cdl_size(&ps->stacks.b)
		&& (b_top->id == l || b_top->id < (r - l + 1) / RB_SIZE + l + 1))
	{
		ft_rr(NULL, &ps->stacks.b, ps, TRUE);
	}
}

static void
	pb(t_pushswap *ps, int l, int r, int *targets)
{
	ft_pb(&ps->stacks.a, &ps->stacks.b, ps, TRUE);
	(*targets)--;
	rb(ps, l, r);
}

void
	ft_pb_and_rotate_a(t_pushswap *ps, int *l, int r, t_bool is_first)
{
	int		targets;
	t_dnode	*a_top;
	t_bool	flag;

	targets = 0;
	if (*l <= r)
		targets = r - *l + 1;
	a_top = ps->stacks.a.head->next;
	flag = FALSE;
	while (targets && a_top != ps->stacks.a.head)
	{
		if (is_first == FALSE)
			skip_target(&ps->stacks, l, &targets, &flag);
		if (sa(ps, r))
			;
		else if (*l <= a_top->id && a_top->id <= r)
			pb(ps, *l, r, &targets);
		else if (targets)
			ft_rr(&ps->stacks.a, NULL, ps, TRUE);
		a_top = ps->stacks.a.head->next;
	}
}
