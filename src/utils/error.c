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

int dup_err(int *sort_arr, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (sort_arr[i] == sort_arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void err_free_args(char ***args, int index)
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

void	free_err(t_node **stack)
{
	free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	err(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
