#include "../../inc/push_swap.h"

void	free_block(char **sub_args)
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

void	free_all_args(char ***args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free_block(args[i]);
		i++;
	}
	free(args);
}

void	abort_parse(char ***args, int *num_arr)
{
	if (num_arr)
		free(num_arr);
	if (args)
		free_all_args(args);
	err();
}