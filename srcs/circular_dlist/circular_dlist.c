#include "circular_dlist.h"

static int
	is_empty(const t_dlist *dlist)
{
	return (dlist->head->next == dlist->head);
}

static void
	set_dnode(t_dnode *node, int n, t_dnode *prev, t_dnode *next)
{
	node->n = n;
	node->prev = prev;
	node->next = next;
}

int
	cdl_init_dlist(t_dlist *dlist)
{
	t_dnode	*dummy_node;

	dummy_node = (t_dnode *)ft_calloc(1, sizeof(t_dnode));
	if (!dummy_node)
		return (0);
	dlist->head = dummy_node;
	dlist->crnt = dummy_node;
	dummy_node->prev = dummy_node;
	dummy_node->next = dummy_node;
	return (1);
}

static int
	insert_after(t_dlist *dlist, t_dnode *prev, int n)
{
	t_dnode	*new_node;
	t_dnode	*next;

	new_node = (t_dnode *)ft_calloc(1, sizeof(t_dnode));
	if (!new_node)
		return (0);
	next = prev->next;
	prev->next->prev = new_node;
	prev->next = new_node;
	set_dnode(new_node, n, prev, next);
	dlist->crnt = new_node;
	return (1);
}

int
	cdl_add_front_dlist(t_dlist *dlist, int n)
{
	return (insert_after(dlist, dlist->head, n));
}

int
	cdl_add_back_dlist(t_dlist *dlist, int n)
{
	return (insert_after(dlist, dlist->head->prev, n));
}

t_dnode
	*cdl_search(t_dlist *dlist, int x, int compare(int x, int y))
{
	t_dnode	*ptr;

	ptr = dlist->head->next;
	while (ptr != dlist->head)
	{
		if (compare(ptr->n, x) == 0)
		{
			dlist->crnt = ptr;
			return (ptr);
		}
		ptr = ptr->next;
	}
	return (NULL);
}

size_t
	cdl_size(const t_dlist *dlist)
{
	t_dnode	*ptr;
	size_t	cnt;

	cnt = 0;
	if (is_empty(dlist))
		return (cnt);
	ptr = dlist->head->next;
	while (ptr != dlist->head)
	{
		ptr = ptr->next;
		cnt++;
	}
	return (cnt);
}

#include <stdio.h>
#include <string.h>
void
	cdl_print_dlist(const t_dlist *dlist)
{
	const char	*msg = "no data\n";
	t_dnode		*ptr;

	if (is_empty(dlist))
		write(STDOUT_FILENO, msg, strlen(msg));
	else
	{
		ptr = dlist->head->next;
		while (ptr != dlist->head)
		{
			printf("%d\n", ptr->n);
			ptr = ptr->next;
		}
	}
}

static void
	remove_node(t_dlist *dlist, t_dnode *p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	dlist->crnt = p->prev;
	free(p);
	if (dlist->crnt == dlist->head)
		dlist->crnt = dlist->head->next;
}

void
	cdl_remove_front(t_dlist *dlist)
{
	if (!is_empty(dlist))
		remove_node(dlist, dlist->head->next);
}

void
	cdl_clear(t_dlist *dlist)
{
	while (!is_empty(dlist))
		cdl_remove_front(dlist);
}

void
	cdl_terminate(t_dlist *dlist)
{
	cdl_clear(dlist);
	free(dlist->head);
}
