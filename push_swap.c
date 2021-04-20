#include "headers/push_swap.h"

void sort_list(t_list *a)
{
	t_list	*b;
	int		size;

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
	}
	exec_and_display("pa", &a, &b, ft_lstsize(b));
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
