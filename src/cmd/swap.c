#include "../../inc/push_swap.h"

static void	swap(t_node **stack)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_node **a)
{
	swap(a);
}

void	sb(t_node **b)
{
	swap(b);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
}
