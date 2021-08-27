/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 22:47:02 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/27 21:41:13 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int
	is_valid_line(const char *line, int ret)
{
	if (ret == GNL_EOF && *line == '\0')
		return (0);
	else if (!ft_strcmp(line, OP_PA)
		|| !ft_strcmp(line, OP_PB)
		|| !ft_strcmp(line, OP_SA)
		|| !ft_strcmp(line, OP_SB)
		|| !ft_strcmp(line, OP_SS)
		|| !ft_strcmp(line, OP_RA)
		|| !ft_strcmp(line, OP_RB)
		|| !ft_strcmp(line, OP_RR)
		|| !ft_strcmp(line, OP_RRA)
		|| !ft_strcmp(line, OP_RRB)
		|| !ft_strcmp(line, OP_RRR))
	{
		return (1);
	}
	return (0);
}

static void
	read_ans(t_pushswap *ps)
{
	char	*line;
	char	*op;
	int		ret;

	while (1)
	{
		op = NULL;
		ret = get_next_line(STDIN_FILENO, &line);
		if (0 <= ret)
		{
			if (line && is_valid_line(line, ret))
				op = ft_strdup(line);
			if (op)
				ft_add_ans(ps, op);
			if (line)
				free(line);
			if (!op && ret != GNL_EOF)
				ret = GNL_ERROR;
		}
		if (ret <= 0)
			break ;
	}
	get_next_line(STDIN_FILENO, NULL);
	if (ret == GNL_ERROR)
		ft_exit_failure(ps);
}

static void
	exec_op(t_pushswap *ps, const char *op)
{
	if (!ft_strcmp(op, OP_PA))
		ft_pa(&ps->stacks.a, &ps->stacks.b, ps, FALSE);
	else if (!ft_strcmp(op, OP_PB))
		ft_pb(&ps->stacks.a, &ps->stacks.b, ps, FALSE);
	else if (!ft_strcmp(op, OP_SA))
		ft_ss(&ps->stacks.a, NULL, ps, FALSE);
	else if (!ft_strcmp(op, OP_SB))
		ft_ss(NULL, &ps->stacks.b, ps, FALSE);
	else if (!ft_strcmp(op, OP_SS))
		ft_ss(&ps->stacks.a, &ps->stacks.b, ps, FALSE);
	else if (!ft_strcmp(op, OP_RA))
		ft_rr(&ps->stacks.a, NULL, ps, FALSE);
	else if (!ft_strcmp(op, OP_RB))
		ft_rr(NULL, &ps->stacks.b, ps, FALSE);
	else if (!ft_strcmp(op, OP_RR))
		ft_rr(&ps->stacks.a, &ps->stacks.b, ps, FALSE);
	else if (!ft_strcmp(op, OP_RRA))
		ft_rrr(&ps->stacks.a, NULL, ps, FALSE);
	else if (!ft_strcmp(op, OP_RRB))
		ft_rrr(NULL, &ps->stacks.b, ps, FALSE);
	else if (!ft_strcmp(op, OP_RRR))
		ft_rrr(&ps->stacks.a, &ps->stacks.b, ps, FALSE);
}

static void
	checker(t_pushswap *ps)
{
	t_list	*ans_ptr;

	ans_ptr = ps->ans;
	while (ans_ptr)
	{
		exec_op(ps, ans_ptr->content);
		ans_ptr = ans_ptr->next;
	}
	if (cdl_is_sorted(
			ps->stacks.a.head, ps->stacks.a.head->next, ft_is_asc_order)
		&& cdl_is_empty(&ps->stacks.b))
	{
		ft_putendl_fd(MSG_CHECKER_OK, STDOUT_FILENO);
	}
	else
		ft_putendl_fd(MSG_CHECKER_KO, STDOUT_FILENO);
}

int
	main(int argc, char **argv)
{
	t_pushswap	ps;
	t_list		*sort_list;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	if (!ft_is_valid_args(argc, argv) || !ft_init_pushswap(&ps, PG_CHECKER))
	{
		ft_putendl_fd(MSG_ERR, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!ft_make_sort_list(&sort_list, argc, argv))
	{
		ft_lstclear(&sort_list, free);
		ft_exit_failure(&ps);
	}
	if (!ft_make_stack_a(&ps.stacks, &sort_list))
		ft_exit_failure(&ps);
	read_ans(&ps);
	checker(&ps);
	ft_exit_success(&ps);
}
