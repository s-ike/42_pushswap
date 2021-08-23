/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ans_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 22:01:25 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/23 23:42:25 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	ft_add_ans(t_list **ans, char *op)
{
	t_list	*op_node;

	op_node = ft_lstnew(op);
	if (!op_node)
		return (0);
	ft_lstadd_back(ans, op_node);
	return (1);
}

static int
	cut_redo_ans(t_list *ans_crnt)
{
	t_list	*first_ptr;
	t_list	*second_ptr;

	first_ptr = ans_crnt->next;
	if (first_ptr->next == NULL)
		return (0);
	second_ptr = first_ptr->next;
	if ((!ft_strcmp(first_ptr->content, OP_PA) && !ft_strcmp(second_ptr->content, OP_PB))
		|| (!ft_strcmp(first_ptr->content, OP_PB) && !ft_strcmp(second_ptr->content, OP_PA))
		|| (!ft_strcmp(first_ptr->content, OP_RB) && !ft_strcmp(second_ptr->content, OP_RRB)))
	{
		ans_crnt->next = second_ptr->next;
		ft_lstdelone(first_ptr, free);
		ft_lstdelone(second_ptr, free);
		return (1);
	}
	return (0);
}

static void
	replace_and_cut_ans(t_list *first_ptr, const char *new_op)
{
	t_list	*second_ptr;

	second_ptr = first_ptr->next;
	first_ptr->next = second_ptr->next;
	ft_strlcpy(first_ptr->content, new_op, ft_strlen(new_op) + 1);
	ft_lstdelone(second_ptr, free);
}

static void
	change_long_ans(t_list *ans_crnt)
{
	t_list	*first_ptr;
	t_list	*second_ptr;

	first_ptr = ans_crnt->next;
	if (first_ptr->next == NULL)
		return ;
	second_ptr = first_ptr->next;
	if (!ft_strcmp(first_ptr->content, OP_RA) && !ft_strcmp(second_ptr->content, OP_RB))
		replace_and_cut_ans(first_ptr, OP_RR);
	else if (!ft_strcmp(first_ptr->content, OP_RB) && !ft_strcmp(second_ptr->content, OP_RA))
		replace_and_cut_ans(first_ptr, OP_RR);
}

int
	ft_optimize_ans(t_list *ans)
{
	int		flag;
	t_list	*ptr;

	flag = 1;
	while (flag)
	{
		flag = 0;
		ptr = ans;
		while (ptr->next)
		{
			change_long_ans(ptr);
			if (cut_redo_ans(ptr))
				flag = 1;
			ptr = ptr->next;
		}
	}
	return (1);
}
