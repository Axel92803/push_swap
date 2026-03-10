#include "../inc/push_swap.h"

static double gargantua(int argc, char **argv, t_node **a, t_strategy *flag)
{
	char	***args;
	int		*flat_array;
	int		*rank;
	int		size;
	double	dis;
	int		start;
	int		i;

	start = parse_arg(argc, argv, flag);
	args = split_arg(argc, argv, start, &size);
	flat_array = parse_num(args, size);
	rank = rank_sort(flat_array, size);

	i = 0;
	while (i < size)
	{
		append_node(a, flat_array[i], rank[i]);
		i++;
	}

	dis = disorder_calc(flat_array, size);

	free(flat_array);
	free(rank);
	free_all_args(args);

	return (dis);
}

static void	selector(t_node	**a, t_node	**b, double	dis, t_strategy flag)
{
	(void)a;
	(void)b;

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
		return ;	//sort_simple(a, b);
	else if (flag == MEDIUM)
		return ;	//sort_medium(a, b);
	else if (flag == COMPLEX)
		return ;	//sort_complex(a, b);
}

static void	print_stack(t_node **a)
{
	t_node	*tail;

	if (!*a)
		return ;
	tail = (*a)->prev;
	while ((*a) != tail)
	{
		printf("%d ", (*a)->val);
		printf("%d\n", (*a)->index);
		*a = (*a)->next;
	}
	printf("%d ", tail->val);
	printf("%d\n", tail->index);
	return ;
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
	print_stack(&a);
	free_stack(&a);
	return (0);
}

