/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:40:50 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/28 17:49:50 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int64_t
	sort_list_n_order(t_list *left, t_list *right)
{
	int64_t	ln;
	int64_t	rn;

	ln = ((t_sort *)left->content)->n;
	rn = ((t_sort *)right->content)->n;
	return (ln - rn);
}

static int64_t
	sort_list_org_order(t_list *left, t_list *right)
{
	int64_t	li;
	int64_t	ri;

	li = ((t_sort *)left->content)->org_idx;
	ri = ((t_sort *)right->content)->org_idx;
	return (li - ri);
}

static t_sort
	*make_new_sort(int idx, int n)
{
	t_sort	*sort;

	sort = (t_sort *)malloc(sizeof(t_sort));
	if (!sort)
		return (NULL);
	sort->id = 0;
	sort->org_idx = idx;
	sort->n = n;
	return (sort);
}

void
	set_id(t_list **sort_list)
{
	t_list	*ptr;
	t_sort	*sort_info;
	int		id;

	id = 0;
	ptr = *sort_list;
	while (ptr)
	{
		sort_info = ptr->content;
		sort_info->id = id++;
		ptr = ptr->next;
	}
}

int
	ft_make_sort_list(t_list **sort_list, int argc, char **argv)
{
	t_list	*sort_node;
	t_sort	*sort_info;
	int		i;

	*sort_list = NULL;
	i = 0;
	while (++i < argc)
	{
		sort_info = make_new_sort(i - 1, ft_atoi(argv[i]));
		if (!sort_info)
			return (0);
		sort_node = ft_lstnew(sort_info);
		if (!sort_node)
		{
			free(sort_info);
			return (0);
		}
		ft_lstadd_front(sort_list, sort_node);
	}
	ft_sort_list(sort_list, sort_list_n_order);
	if (!ft_check_dup_n(sort_list))
		return (0);
	set_id(sort_list);
	ft_sort_list(sort_list, sort_list_org_order);
	return (1);
}
