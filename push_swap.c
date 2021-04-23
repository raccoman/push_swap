#include "./headers/push_swap.h"

void	finish_sorting(t_list *a, int size, int *median)
{
	int	min_index;

	if (size > 5)
		free(median);
	median++;
	min_index = find_index_of_min(a);
	if (min_index <= size / 2)
		execute("ra", &a, NULL, min_index);
	else
		execute("rra", &a, NULL, size - min_index);
}

void	sort_list(t_list *a)
{
	t_list	*b;
	int		size;
	int		*median;

	b = NULL;
	size = ft_lstsize(a);
	if (check_sorted(a) || size == 1)
		return ;
	while (!check_sorted(a))
	{
		if (size == 2)
			sort_2(a);
		else if (size == 3)
			sort_3(&a);
		else if (size == 4)
			sort_4(&a, &b);
		else if (size == 5)
			sort_5(&a, &b);
		else
			median = sort_n(&a, &b);
		size = ft_lstsize(a);
	}
	finish_sorting(a, size, median);
}

int	main(int argc, char *argv[])
{
	t_list	*list;

	if (argc == 1)
		return (1);
	list = parse_args(argc, argv);
	if (!list)
		return (1);
	sort_list(list);
	ft_lstclear(&list);
}
