#include "headers/push_swap.h"

static int find_index_of_min(t_list *list)
{
    int min;
    int index;
    int i;

    min = 2147483647;
    index = 0;
    i = 0;
    while (list)
    {
        if ((*(int *)(list->data)) < min)
        {
            min = (*(int *)(list->data));
            index = i;
        }
        list = list->next;
        i++;
    }
    return (index);
}

/*static void print_list(t_list *list)
{
	while (list)
	{
		printf("%d\n", *((int *)(list->data)));
		list = list->next;
	}
}*/

void sort_list(t_list *a)
{
	t_list	*b;
	int		size;
	//int		max_index;

	b = NULL;
	size = ft_lstsize(a);
	if ((!b && check_sorted(a)) || size == 1)
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
			sort_n(&a, &b);
		size = ft_lstsize(a);
	}
	int quicker = find_index_of_min(a);
	if (quicker <= size / 2)
		exec_and_display("ra", &a, NULL, quicker);
	else
		exec_and_display("rra", &a, NULL, size - quicker);
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
