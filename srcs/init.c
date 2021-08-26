/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:53:56 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/26 18:07:53 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	ft_make_stack_a(t_stacks *stacks, t_list **sort_list)
{
	t_list	*ptr;
	t_sort	*sort_info;

	ptr = *sort_list;
	while (ptr)
	{
		sort_info = ptr->content;
		if (!cdl_add_back_dlist(&stacks->a, sort_info->n, sort_info->id))
		{
			ft_lstclear(sort_list, free);
			return (0);
		}
		ptr = ptr->next;
	}
	ft_lstclear(sort_list, free);
	return (1);
}

int
	ft_init_stacks(t_stacks *stacks)
{
	if (cdl_init_dlist(&stacks->a))
		return (cdl_init_dlist(&stacks->b));
	cdl_terminate(&stacks->a);
	return (0);
}

void
	ft_terminate_stacks(t_stacks *stacks)
{
	cdl_terminate(&stacks->a);
	cdl_terminate(&stacks->b);
	return ;
}

int
	ft_init_pushswap(t_pushswap *ps)
{
	if (ft_init_stacks(&ps->stacks))
	{
		ps->ans = NULL;
		return (1);
	}
	return (0);
}
