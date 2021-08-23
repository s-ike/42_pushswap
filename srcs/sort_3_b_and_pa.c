/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_b_and_pa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 00:58:25 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/23 01:53:19 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int
	pa(t_pushswap *ps, size_t n)
{
	int	ret;
	t_dlist	*a;
	t_dlist	*b;

	a = &ps->stacks->a;
	b = &ps->stacks->b;
	if (n <= 0)
		return (1);
	ret = ft_pa(a, b, ps);
	n--;
	while (n-- && ret)
		ret = ft_pa(a, b, ps);
	return (ret);
}

static int
	sort_2_and_pa(t_pushswap *ps)
{
	t_dlist	*b;
	int		x;
	int		y;

	b = &ps->stacks->b;
	x = b->head->next->n;
	y = b->head->next->next->n;
	if (x < y)
		ft_ss(NULL, b, ps);
	return (pa(ps, 2));
}

/*
if (n[1] < n[0] && n[0] < n[2])      // 2,1,3
else if (n[2] < n[1] && n[1] < n[0]) // 1.2.3
else if (n[0] < n[2] && n[2] < n[1]) // 1,3,2
else if (n[2] < n[0] && n[0] < n[1]) // 2,3,1
else if (n[1] < n[2] && n[2] < n[0]) // 3,1,2
*/
static int
	sort_3_and_pa(t_pushswap *ps)
{
	int	n[3];
	t_dlist	*b;

	b = &ps->stacks->b;
	n[0] = b->head->next->n;
	n[1] = b->head->next->next->n;
	n[2] = b->head->next->next->next->n;
	if (n[1] < n[0] && n[0] < n[2])
		ft_rrr(NULL, b, ps);
	else if (n[0] < n[1] && n[1] < n[2])
	{
		ft_ss(NULL, b, ps);
		ft_rrr(NULL, b, ps);
	}
	else if (n[0] < n[2] && n[2] < n[1])
		ft_rr(NULL, b, ps);
	else if (n[2] < n[0] && n[0] < n[1])
		ft_ss(NULL, b, ps);
	else if (n[1] < n[2] && n[2] < n[0])
	{
		if (ft_pa(&ps->stacks->a, b, ps))
			ft_ss(NULL, b, ps);
		else
			return (0);
	}
	return (pa(ps, cdl_size(b)));
}

int
	ft_sort_3_b_and_pa(t_pushswap *ps)
{
	size_t	size;

	size = cdl_size(&ps->stacks->b);
	if (size == 2)
		return (sort_2_and_pa(ps));
	else
		return (sort_3_and_pa(ps));
}
