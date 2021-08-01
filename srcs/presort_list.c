#include "push_swap.h"

static int
	sort_list_n_order(t_list *left, t_list *right)
{
	t_sort	*l;
	t_sort	*r;

	l = (t_sort *)left->content;
	r = (t_sort *)right->content;
	return (l->n - r->n);
}

static int
	sort_list_org_order(t_list *left, t_list *right)
{
	t_sort	*l;
	t_sort	*r;

	l = (t_sort *)left->content;
	r = (t_sort *)right->content;
	return (l->org_idx - r->org_idx);
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
	t_sort	*sort;
	int		i;

	*sort_list = NULL;
	i = 1;
	while (i < argc)
	{
		sort_node = NULL;
		sort = make_new_sort(i - 1, ft_atoi(argv[i]));
		if (sort)
			sort_node = ft_lstnew(sort);
		if (!sort || !sort_node)
		{
			ft_lstclear(sort_list, free);
			return (0);
		}
		ft_lstadd_front(sort_list, sort_node);
		i++;
	}
	ft_sort_list(sort_list, sort_list_n_order);
	set_id(sort_list);
	ft_sort_list(sort_list, sort_list_org_order);
	return (1);
}
