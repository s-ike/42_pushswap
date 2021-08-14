/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_b_and_pa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 00:58:25 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/15 01:00:28 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int
	pa(t_stacks *stacks, size_t n)
{
	int	ret;

	if (n <= 0)
		return (1);
	ret = ft_pa(&stacks->a, &stacks->b);
	n--;
	while (n-- && ret)
		ret = ft_pa(&stacks->a, &stacks->b);
	return (ret);
}

static int
	sort_2_and_pa(t_stacks *stacks)
{
	t_dlist	*a;
	t_dlist	*b;
	int		x;
	int		y;

	a = &stacks->a;
	b = &stacks->b;
	x = b->head->next->n;
	y = b->head->next->next->n;
	if (x < y)
		ft_ss(NULL, b);
	return (pa(stacks, 2));
}

/*
if (n[1] < n[0] && n[0] < n[2])      // 2,1,3
else if (n[2] < n[1] && n[1] < n[0]) // 1.2.3
else if (n[0] < n[2] && n[2] < n[1]) // 1,3,2
else if (n[2] < n[0] && n[0] < n[1]) // 2,3,1
else if (n[1] < n[2] && n[2] < n[0]) // 3,1,2
*/
static int
	sort_3_and_pa(t_stacks *stacks)
{
	int	n[3];

	n[0] = stacks->b.head->next->n;
	n[1] = stacks->b.head->next->next->n;
	n[2] = stacks->b.head->next->next->next->n;
	if (n[1] < n[0] && n[0] < n[2])
		ft_rrr(NULL, &stacks->b);
	else if (n[0] < n[1] && n[1] < n[2])
	{
		ft_ss(NULL, &stacks->b);
		ft_rrr(NULL, &stacks->b);
	}
	else if (n[0] < n[2] && n[2] < n[1])
		ft_rr(NULL, &stacks->b);
	else if (n[2] < n[0] && n[0] < n[1])
		ft_ss(NULL, &stacks->b);
	else if (n[1] < n[2] && n[2] < n[0])
	{
		if (ft_pa(&stacks->a, &stacks->b))
			ft_ss(NULL, &stacks->b);
		else
			return (0);
	}
	return (pa(stacks, cdl_size(&stacks->b)));
}

int
	ft_sort_3_b_and_pa(t_stacks *stacks)
{
	size_t	size;

	size = cdl_size(&stacks->b);
	if (size == 2)
		return (sort_2_and_pa(stacks));
	else
		return (sort_3_and_pa(stacks));
}
