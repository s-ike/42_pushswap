/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:31:21 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/27 21:33:40 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifdef LEAKS

void
	ft_exit_failure(t_pushswap *ps)
{
	ft_terminate_stacks(&ps->stacks);
	if (ps->ans)
		ft_lstclear(&ps->ans, free);
	ft_putendl_fd(MSG_ERR, STDERR_FILENO);
	if (ps->prg == PG_PUSHSWAP)
		system("leaks push_swap");
	else if (ps->prg == PG_CHECKER)
		system("leaks checker");
	exit(EXIT_FAILURE);
}

void
	ft_exit_success(t_pushswap *ps)
{
	ft_terminate_stacks(&ps->stacks);
	if (ps->ans)
		ft_lstclear(&ps->ans, free);
	if (ps->prg == PG_PUSHSWAP)
		system("leaks push_swap");
	else if (ps->prg == PG_CHECKER)
		system("leaks checker");
	exit(EXIT_SUCCESS);
}
#else

void
	ft_exit_failure(t_pushswap *ps)
{
	ft_terminate_stacks(&ps->stacks);
	if (ps->ans)
		ft_lstclear(&ps->ans, free);
	ft_putendl_fd(MSG_ERR, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void
	ft_exit_success(t_pushswap *ps)
{
	ft_terminate_stacks(&ps->stacks);
	if (ps->ans)
		ft_lstclear(&ps->ans, free);
	exit(EXIT_SUCCESS);
}
#endif
