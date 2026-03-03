#include "../../inc/push_swap.h"

int	syntax_err(char *argv)
{
	int	i;

	i = 0;
	if (!argv[0])
		return (0);
	if (argv[0] == '+' || argv[0] == '-')
	{
		if (!ft_isdigit(argv[i + 1]))
			return (0);
		i++;
	}
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	dup_err(t_node **a, int num)
{
	t_node *tmp;
	if (!*a)
		return (1);
	tmp = *a;
	while (tmp->next != *a)
	{
		if (tmp->val == num)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->val == num)
		return (0);
	return (1);
}


void	free_err(t_node **stack)
{
	free(*stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
