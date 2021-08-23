/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:09:50 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/23 00:57:08 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
if (n[2] < n[3] && n[3] < n[1])      // 1,4,2,3
else if (n[3] < n[1] && n[1] < n[2]) // 1,3,4,2
*/
static void
	sort_4_minidx1(t_dlist *a, int *n, t_pushswap *ps)
{
	if (n[2] < n[3] && n[3] < n[1])
	{
		ft_ss(a, NULL, ps);
		ft_rr(a, NULL, ps);
	}
	else if (n[3] < n[1] && n[1] < n[2])
	{
		ft_rrr(a, NULL, ps);
		ft_ss(a, NULL, ps);
	}
}

/*
if (n[0] < n[2] && n[2] < n[3])      // 2,1,3,4
else if (n[3] < n[0] && n[0] < n[2]) // 3,1,4,2
*/
static void
	sort_4_minidx2(t_dlist *a, int *n, t_pushswap *ps)
{
	if (n[0] < n[2] && n[2] < n[3])
		ft_ss(a, NULL, ps);
	else if (n[3] < n[0] && n[0] < n[2])
	{
		ft_rr(a, NULL, ps);
		ft_ss(a, NULL, ps);
		ft_rr(a, NULL, ps);
	}
}

/*
if (n[0] < n[1] && n[1] < n[3])      // 2,3,1,4
else if (n[1] < n[3] && n[3] < n[0]) // 4,2,1,3
*/
static void
	sort_4_minidx3(t_dlist *a, int *n, t_pushswap *ps)
{
	if (n[0] < n[1] && n[1] < n[3])
	{
		ft_rrr(a, NULL, ps);
		ft_rrr(a, NULL, ps);
		ft_ss(a, NULL, ps);
		ft_rr(a, NULL, ps);
	}
	else if (n[1] < n[3] && n[3] < n[0])
	{
		ft_rr(a, NULL, ps);
		ft_ss(a, NULL, ps);
	}
}

/*
if (n[2] < n[0] && n[0] < n[1])      // 3,4,2,1
else if (n[1] < n[2] && n[2] < n[0]) // 4,2,3,1
*/
static void
	sort_4_minidx4(t_dlist *a, int *n, t_pushswap *ps)
{
	if (n[2] < n[0] && n[0] < n[1])
	{
		ft_rrr(a, NULL, ps);
		ft_rrr(a, NULL, ps);
		ft_ss(a, NULL, ps);
	}
	else if (n[1] < n[2] && n[2] < n[0])
	{
		ft_rrr(a, NULL, ps);
		ft_ss(a, NULL, ps);
		ft_rr(a, NULL, ps);
	}
}

void
	ft_sort_4(t_dlist *a, t_pushswap *ps)
{
	int		n[4];
	size_t	min_idx;

	n[0] = a->head->next->n;
	n[1] = a->head->next->next->n;
	n[2] = a->head->next->next->next->n;
	n[3] = a->head->next->next->next->next->n;
	min_idx = cdl_get_min_node_idx(a);
	if (min_idx == 1)
		sort_4_minidx1(a, n, ps);
	else if (min_idx == 2)
		sort_4_minidx2(a, n, ps);
	else if (min_idx == 3)
		sort_4_minidx3(a, n, ps);
	else if (min_idx == 4)
		sort_4_minidx4(a, n, ps);
}
