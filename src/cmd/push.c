#include "../../inc/push_swap.h"

static t_node *pop(t_node **src)
{
	t_node *node;

	node = NULL;
	if (!*src)
		return node;
	node = *src;
	if ((*src)->next == *src)
		*src = NULL;
	else
	{
		*src = (*src)->next;
		(*src)->prev = node->prev;
		node->prev->next = *src;
	}
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static void	push(t_node **dst, t_node **src)
{
	t_node *new_node;

	new_node = pop(src);
	if (!new_node)
		return ;
	if (!*dst)
	{
		*dst = new_node;
		(*dst)->next = *dst;
		(*dst)->prev = *dst;
	}
	else
	{
		new_node->next = *dst;
		new_node->prev = (*dst)->prev;
		(*dst)->prev->next = new_node;
		(*dst)->prev = new_node;
		*dst = new_node;
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
