/*
gcc -Wall -Wextra -Werror -I../includes -I../libft -L../libft -lft circular_dlist.c circular_dlist_test.c
gcc -Wall -Wextra -Werror circular_dlist.c circular_dlist_test.c -D TEST
*/
#include <stdlib.h>
#include <unistd.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (0 < len--)
		*ptr++ = c;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, count * size);
	return (p);
}


typedef struct s_dnode
{
	int				n;
	struct s_dnode	*prev;
	struct s_dnode	*next;
}	t_dnode;

typedef struct s_dlist
{
	t_dnode	*head;
	t_dnode	*crnt;
}	t_dlist;

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
	ft_init_dlist(t_dlist *dlist)
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
	ft_add_front_dlist(t_dlist *dlist, int n)
{
	return (insert_after(dlist, dlist->head, n));
}

int
	ft_add_back_dlist(t_dlist *dlist, int n)
{
	return (insert_after(dlist, dlist->head->prev, n));
}

void
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
	remove_front(t_dlist *dlist)
{
	if (!is_empty(dlist))
		remove_node(dlist, dlist->head->next);
}

void
	clear(t_dlist *dlist)
{
	while (!is_empty(dlist))
		remove_front(dlist);
}

void
	terminate(t_dlist *dlist)
{
	clear(dlist);
	free(dlist->head);
}

/*
表示系
*/
// static int
// 	next(t_dlist *dlist)
// {
// 	if (is_empty(dlist) || dlist->crnt->next == dlist->head)
// 		return (0);
// 	dlist->crnt = dlist->crnt->next;
// 	return (1);
// }

// static int
// 	prev(t_dlist *dlist)
// {
// 	if (is_empty(dlist) || dlist->crnt->prev == dlist->head)
// 		return (0);
// 	dlist->crnt = dlist->crnt->prev;
// 	return (1);
// }

#include <stdio.h>
#include <string.h>
void
	print_dlist(const t_dlist *dlist)
{
	const char	*msg = "no data\n";

	if (is_empty(dlist))
		write(STDOUT_FILENO, msg, strlen(msg));
	else
	{
		t_dnode	*ptr;

		ptr = dlist->head->next;
		while (ptr != dlist->head)
		{
			printf("%d\n", ptr->n);
			ptr = ptr->next;
		}
	}
}

/**********************************
MAIN
**********************************/

int	main(int ac, char **av)
{
	t_dlist	dlist;
	int		i = 1;

	// int		ac = 5;
	// char	*av[] = {"a.out", "1", "2", "3", "4", NULL};

	if (ac < 2)
		return (1);
	ft_init_dlist(&dlist);
	while (i < ac)
		ft_add_back_dlist(&dlist, atoi(av[i++]));
	print_dlist(&dlist);
	terminate(&dlist);
	system("leaks a.out");
	return (0);
}
