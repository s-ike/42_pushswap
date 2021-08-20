/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:31:21 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/20 11:13:15 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifdef LEAKS

void
	ft_exit_failure(t_stacks *stacks)
{
	ft_terminate_stacks(stacks);
	ft_putendl_fd(MSG_ERR, STDERR_FILENO);
	system("leaks push_swap");
	exit(EXIT_FAILURE);
}

void
	ft_exit_success(t_stacks *stacks)
{
	ft_terminate_stacks(stacks);
	system("leaks push_swap");
	exit(EXIT_SUCCESS);
}
#else

void
	ft_exit_failure(t_stacks *stacks)
{
	ft_terminate_stacks(stacks);
	ft_putendl_fd(MSG_ERR, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void
	ft_exit_success(t_stacks *stacks)
{
	ft_terminate_stacks(stacks);
	exit(EXIT_SUCCESS);
}
#endif
