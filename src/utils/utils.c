#include "../../inc/push_swap.h"

static void	free_block(char **sub_args)
{
	size_t	i;

	if (!sub_args)
		return ;
	i = 0;
	while (sub_args[i])
	{
		free(sub_args[i]);
		i++;
	}
	free(sub_args);
}

void free_args(char ***args, int index)
{

	int	i;

	i = 0;
	while (i < index)
	{
		free_block(args[i]);
		i++;
	}
	free(args);
}

void	free_stack(t_node **stack)
{
	t_node	*head;
	t_node	*next;
	t_node	*tmp;

	if(!*stack || !stack)
		return ;
	head = (*stack);
	tmp = head->next;
	while(tmp != head)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(head);
	*stack = NULL;
}