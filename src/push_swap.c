#include "../inc/push_swap.h"

static double gargantua(int argc, char **argv, t_node **a, t_strategy *flag)
{
	char ***args;
	int		*flat_array;
	int		size;
	double	dis;

	args = split_arg(argc, argv);
	size = count_args(args);
	flat_array = parse_num(args, a);
	parse_arg(argc, argv, flag);
	dis = disorder_calc(flat_array, size);

	free(flat_array);
	free_args(args, argc - parse_arg(argc, argv, flag));

	return (dis);
}

static void	selector(t_node	**a, t_node	**b, double	dis, t_strategy flag)
{
	if (flag == ADAPTIVE)
	{
		if (dis < 0.2)
			flag = SIMPLE;
		else if (dis >= 0.2 && dis < 0.5)
			flag = MEDIUM;
		else
			flag = COMPLEX;
	}
	if (flag == SIMPLE)
		sort_simple(a, b);
	else if (flag == MEDIUM)
		sort_medium(a, b);
	else if (flag == COMPLEX)
		sort_complex(a, b);
}

int	main(int argc, char **argv)
{
	t_node		*a;
	t_node 		*b;
	t_strategy	flag;
	double		dis;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	dis = gargantua(argc, argv, &a, &flag);
	selector(&a, &b, dis, flag);
	return (0);
}

