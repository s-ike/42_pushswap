/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 03:45:29 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/28 18:35:37 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	cdl_ncmp(int n1, int n2)
{
	if (n1 < n2)
		return (-1);
	else if (n1 > n2)
		return (1);
	else
		return (0);
}
