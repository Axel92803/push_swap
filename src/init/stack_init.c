#include "../../inc/push_swap.h"

void	append_node(t_node **a, int num)
{
	t_node	*new;

	if (!a)
		err();
	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		free_err(&new);
	new->val = num;
	if (!*a)
	{
		*a = new;
		(*a)->next = *a;
		(*a)->prev = *a;
	}
	else
	{
		new->prev = (*a)->prev;
		(*a)->prev->next = new;
		new->next = *a;
		(*a)->prev = new;
	}
}

