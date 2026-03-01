#include "../../inc/push_swap.h"

static void	swap(t_node **stack)
{
	t_node	*tail;

	if (!*stack || (*stack)->next == *stack)
		return ;
	if ((*stack)->next->next == *stack)
		*stack = (*stack)->next;
	else
	{
		tail = (*stack)->prev;
		*stack = (*stack)->next;
		(*stack)->prev->next = (*stack)->next;
		(*stack)->prev->prev = (*stack);
		(*stack)->next->prev = (*stack)->prev;
		(*stack)->next = (*stack)->prev;
		(*stack)->prev = tail;
		tail->next = *stack;
	}
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
