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
			ft_putnbr_fd(ptr->n, STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
			ptr = ptr->next;
		}
	}
}
