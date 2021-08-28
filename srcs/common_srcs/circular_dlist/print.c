/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:45:41 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/14 03:45:41 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_dlist.h"

void
	cdl_print_dlist(const t_dlist *dlist)
{
	const char	*msg = "no data\n";
	t_dnode		*ptr;

	if (cdl_is_empty(dlist))
		write(STDOUT_FILENO, msg, ft_strlen(msg));
	else
	{
		ptr = dlist->head->next;
		while (ptr != dlist->head)
		{
			ft_putchar_fd('[', STDOUT_FILENO);
			ft_putnbr_fd(ptr->id, STDOUT_FILENO);
			ft_putstr_fd("] ", STDOUT_FILENO);
			ft_putnbr_fd(ptr->n, STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
			ptr = ptr->next;
		}
	}
}
