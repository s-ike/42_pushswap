#include "push_swap.h"

static void
	merge_loop(
		t_list **left,
		t_list **right,
		t_list **next,
		int f(t_list *left, t_list *right))
{
	int	comp;

	comp = f(*left, *right);
	if (comp <= 0)
	{
		(*next)->next = *left;
		*next = (*next)->next;
		*left = (*left)->next;
	}
	else
	{
		(*next)->next = *right;
		*next = (*next)->next;
		*right = (*right)->next;
	}
}

static t_list
	*merge(
		t_list *left,
		t_list *right,
		int f(t_list *left, t_list *right))
{
	t_list	head;
	t_list	*next;

	next = &head;
	while (left && right)
		merge_loop(&left, &right, &next, f);
	if (!left)
		next->next = right;
	else
		next->next = left;
	return (head.next);
}

static t_list
	*merge_sort_rec(
		t_list *lst,
		int f(t_list *left, t_list *right))
{
	t_list	*left;
	t_list	*right;
	t_list	*right_head;

	if (!lst || !lst->next)
		return (lst);
	left = lst;
	right = lst->next;
	if (right)
		right = right->next;
	while (right)
	{
		left = left->next;
		right = right->next;
		if (right)
			right = right->next;
	}
	right_head = left->next;
	left->next = NULL;
	return (merge(merge_sort_rec(lst, f), merge_sort_rec(right_head, f), f));
}

void
	ft_sort_list(
		t_list **lst,
		int f(t_list *left, t_list *right))
{
	if (!lst)
		return ;
	*lst = merge_sort_rec(*lst, f);
}
