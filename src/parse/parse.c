#include "../../inc/push_swap.h"

int	parse_arg(int argc, char **argv, t_strategy *strategy)
{
	int	i;

	i = 1;
	*strategy = ADAPTIVE;
	if(argc > 1)
	{
		if(!ft_strncmp(argv[1], "--simple", 9))
			*strategy = SIMPLE;
		else if (!ft_strncmp(argv[1], "--medium", 9))
			*strategy = MEDIUM;
		else if (!ft_strncmp(argv[1], "--complex", 10))
			*strategy = COMPLEX;
		else if (!ft_strncmp(argv[1], "--adaptive", 11))
			*strategy = ADAPTIVE;
		if (!ft_strncmp(argv[1], "--", 2))
			i = 2;
	}
	return (i);
}

int	parse_num(int argc, char **argv, int start, t_node a)
{

	int	i;
	long	num;

	i = start;
	while(i < argc)
	{
		if (!syntax_err(argv[i]))
			free_err(a);
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			free_err(a);
		if (dup_err(a, (int)num))
			free_err(a);
		append_node(a, (int)num);
		i++;
	}
}
