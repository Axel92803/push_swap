#include "../../inc/push_swap.h"

char	***split_arg(int argc, char **argv, int start, int *tot_len)
{
	char	***args;
	int		i;
	int 	j;

	i = 0;
	*tot_len = 0;
	args = (char ***)malloc(sizeof(char **) * (argc - start + 1));
	if (!args)
		return (NULL);
	while (start < argc)
	{
		args[i] = ft_split(argv[start], ' ');
		if (!args[i])
			return (err_free_args(args, i), NULL);
		j = 0;
		while(args[i][j])
		{
			(*tot_len)++;
			j++;
		}
		i++;
		start++;
	}
	args[i] = NULL;
	return (args);
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

void	process_num(char *str, int *num_arr, char ***args, int *z)
{
	long	num;

	if (!syntax_err(str))
		abort_parse(args, num_arr);
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		abort_parse(args, num_arr);
	num_arr[*z] = (int)num;
	(*z)++;
}
