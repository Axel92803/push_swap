#include "../../inc/push_swap.h"

char	***split_arg(int argc, char **argv)
{
	char	***args;
	int		i;
	int		flag;
	t_strategy	dummy;

	i = 0;
	flag = parse_arg(argc, argv, &dummy);
	args = (char ***)malloc(sizeof(char **) * (argc - flag + 1));
	if (!args)
		return (NULL);
	while (((argc >= 3 && flag == 2) || (argc >= 2 && flag == 1)) && flag < argc)
	{
		args[i] = ft_split(argv[flag], ' ');
		if (!args[i])
			return (free_args(args, i), NULL);
		i++;
		flag++;
	}
	args[i] = NULL;
	return (args);
}

int	count_args(char ***args)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (args[i])
	{
		j = 0;
		while(args[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}

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

int	*parse_num(char ***args, t_node **a)
{

	int	i;
	int j;
	int	z;
	int *num_arr;
	long	num;

	i = 0;
	z = 0;
	num_arr = (int *)malloc(sizeof(int) * (count_args(args) + 1));
	while(args[i])
	{
		j = 0;
		while(args[i][j])
		{
			if (!syntax_err(args[i][j]))
				free_err(a);
			num = ft_atol(args[i][j]);
			if (num < INT_MIN || num > INT_MAX)
				free_err(a);
			if (!dup_err(a, (int)num))
				free_err(a);
			append_node(a, (int)num);
			num_arr[z] = (int)num;
			j++;
			z++;
		}
		i++;
	}
	return (num_arr);
}
