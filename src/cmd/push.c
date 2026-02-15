#include "../../inc/push_swap.h"

static void	push(t_node **dst, t_node **src)
{
	t_node *tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->prev = NULL;
	if (!*dst)
	{
		*dst = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *dst;
		tmp->next->prev = tmp;
		*dst = tmp;
	}
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
}
