#include "push_swap.h"

void	exec_and_display(char *cmnd, t_list **a, t_list **b, int times)
{
	int i;

	i = -1;
	while (++i < times)
	{
		write(1, cmnd, ft_strlen(cmnd));
		write(1, "\n", 1);
		dispatcher(cmnd, a, b);
	}
}

void	sort_2(t_list *a)
{
	if ( *((int *)(a->data)) > *((int *)(a->next->data)) )
		exec_and_display("sa", &a, NULL, 1);
}

void	sort_3(t_list **a)
{
	int	top;
	int	middle;
	int	bottom;

	top = *((int *)((*a)->data));
	middle = *((int *)((*a)->next->data));
	bottom = *((int *)((*a)->next->next->data));

	if ((top > middle && middle < bottom && bottom > top)
		|| (top > middle && middle > bottom && bottom < top)
		|| (top < middle && middle > bottom && bottom > top))
	{									           
		exec_and_display("sa", a, NULL, 1);
		top = *((int *)((*a)->data));
		middle = *((int *)((*a)->next->data));
	}
	if (top > middle && middle < bottom && bottom < top)
		exec_and_display("ra", a, NULL, 1); 
	else if (top < middle && middle > bottom && bottom < top)
		exec_and_display("rra", a, NULL, 1);
}

int find_index(t_list *list, int num)
{
	int index;

	index = 0;
	while (list)
	{
		if (*((int *)(list->data)) > num)
			break ;
		index++;
		list = list->next;
	}
	return (index);
}

int find_min(t_list *list)
{
	int min;
	int index;
	int i;

	min = 2147483647;
	i = 0;
	while (list)
	{
		if (*((int *)(list->data)) < min)
		{
			min = *((int *)(list->data));
			index = i;
		}
		i++;
		list = list->next;
	}
	return (index);
}

void insert_sorted(t_list **a, t_list **b, int size)
{
	int index;

	while (*b)
	{
		index = find_index(*a, *((int *)((*b)->data)));
		if (index < (size / 2) && index != 1)
			exec_and_display("ra", a, NULL, index);
		else if (index != 1)
			exec_and_display("rra", a, NULL, (size - index));
		exec_and_display("pa", a, b, 1);
		if (index == 1)
			exec_and_display("sa", a, NULL, 1);
		else if (index < (size / 2))
			exec_and_display("rra", a, NULL, index);
		else
			exec_and_display("ra", a, NULL, (size - index + 1));
		size++;
	}

	/*index = find_index(*a, *((int *)((*b)->data)));
	if (index == 1)
		exec_and_display("ra", a, NULL, 1);
	if (index == 2)
		exec_and_display("rra", a, NULL, 1);
	exec_and_display("pa", a, b, 1);
	if (index == 1)
		exec_and_display("rra", a, NULL, 1);
	if (index == 2)
		exec_and_display("ra", a, NULL, 2);
	if (index == 3)
		exec_and_display("ra", a, NULL, 1);

	index = find_index(*a, *((int *)((*b)->data)));
	if (index == 1)
		exec_and_display("ra", a, NULL, 1);
	if (index == 2)
		exec_and_display("ra", a, NULL, 2);
	if (index == 3)
		exec_and_display("rra", a, NULL, 1);
	exec_and_display("pa", a, b, 1);
	if (index == 1)
		exec_and_display("rra", a, NULL, 1);
	if (index == 2)
		exec_and_display("rra", a, NULL, 2);
	if (index == 3)
		exec_and_display("ra", a, NULL, 2);
	if (index == 4)
		exec_and_display("ra", a, NULL, 1);*/
}

void	sort_4(t_list **a, t_list **b)
{
	exec_and_display("pb", a, b, 1);
	sort_3(a);
	insert_sorted(a, b, 3);
}

void	sort_5(t_list **a, t_list **b)
{
	exec_and_display("pb", a, b, 2);
	sort_3(a);
	insert_sorted(a, b, 3);
}

void sort_n(t_list **a, t_list **b)
{
	a++;
	b++;
}