#include "headers/push_swap.h"

int find_index_of_max(t_list *list)
{
	int max;
	int index;
	int i;

	max = -2147483648;
	index = 0;
	i = 0;
	while (list)
	{
		if ((*(int *)(list->data)) > max)
		{
			max = (*(int *)(list->data));
			index = i;
		}
		list = list->next;
		i++;
	}
	return (index);
}

void sort_list(t_list *a)
{
	t_list	*b;
	int		size;
	int		max_index;

	b = NULL;
	size = ft_lstsize(a);
	if ((!b && check_sorted(a)) || size == 1)
		return ;
	while (!check_sorted(a))
	{
		if (size == 2)
			sort_2(a);
		if (size == 3)
			sort_3(&a);
		if (size == 4)
			sort_4(&a, &b);
		if (size == 5)
			sort_5(&a, &b);
		else
			sort_n(&a, &b);
		size = ft_lstsize(a);
	}
	max_index = find_index_of_max(b);
	size = ft_lstsize(b);
	if (max_index <= size / 2)
		exec_and_display("rb", NULL, &b, max_index);
	else
		exec_and_display("rra", NULL, &b, size - max_index);
	exec_and_display("pa", &a, &b, size);
}

int	main(int narg, char *args[])
{
	t_list	*list;

	if (narg == 1)
		return (1);
	list = parse_args(narg, args);
	if (!list)
		return (1);
	sort_list(list);
	ft_lstclear(&list);
}
