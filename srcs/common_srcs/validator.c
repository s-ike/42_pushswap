/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:10:24 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/20 23:39:14 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	ft_check_dup_n(t_list **sort_list)
{
	t_list	*ptr;
	t_sort	*sort_info;
	int		pre_n;

	sort_info = (*sort_list)->content;
	pre_n = sort_info->n;
	ptr = (*sort_list)->next;
	while (ptr)
	{
		sort_info = ptr->content;
		if (pre_n == sort_info->n)
			return (0);
		pre_n = sort_info->n;
		ptr = ptr->next;
	}
	return (1);
}

static int
	isover_intrange(char *s)
{
	uint64_t	num;
	int			is_minus;

	is_minus = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		is_minus = 1;
	if (*s == '+' || *s == '-')
		s++;
	num = 0;
	while (ft_isdigit(*s))
	{
		num = num * 10 + *s - '0';
		if (is_minus && (uint64_t)__INT_MAX__ + 1 < num)
			return (-1);
		else if (!is_minus && (uint64_t)__INT_MAX__ < num)
			return (1);
		s++;
	}
	return (0);
}

static int
	isnumeric(char *s)
{
	if (!s || *s == '\0')
		return (0);
	if (*s == '+' || *s == '-')
		s++;
	if (!ft_isdigit(*s))
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s++))
			return (0);
	}
	return (1);
}

int
	ft_is_valid_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!isnumeric(argv[i]) || isover_intrange(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
