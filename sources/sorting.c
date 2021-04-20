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

void insert_sorted(t_list **a, t_list **b, int size)
{
	int index;

	while (*b)
	{
		index = find_index(*a, *((int *)((*b)->data)));
		if (index < (size / 2))
			exec_and_display("ra", a, NULL, index - 1);
		else
			exec_and_display("rra", a, NULL, (size - index));
		exec_and_display("pa", a, b, 1);
		if (index <= (size / 2))
		{
			if (index != 0)
				exec_and_display("sa", a, NULL, 1);
			exec_and_display("rra", a, NULL, index - 1);
		}
		else
			exec_and_display("ra", a, NULL, (size - index + 1));
		size++;
	}
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

int find_max(t_list *list)
{
	int max;

	max = -2147483648;
	while (list)
	{
		if ((*(int *)(list->data)) > max)
			max = (*(int *)(list->data));
		list = list->next;
	}
	return (max);
}

int find_min(t_list *list)
{
	int min;

	min = 2147483647;
	while (list)
	{
		if ((*(int *)(list->data)) < min)
			min = (*(int *)(list->data));
		list = list->next;
	}
	return (min);
}

int find_quicker(t_list *a, int median, int size)
{
	int first = -1;
	int last = -1;
	int i = -1;

	while (++i < size)
	{
		if (*(int *)(a->data) <= median)
		{
			if (i <= size / 2 && first == -1)
				first = i;
			else
				last = i;
		}
		a = a->next;					
	}
	if (first == -1 && last == -1)
		return (-1);
	if (first == -1)
		return (last);
	if (last == -1)
		return (first);
	if (first <= size - last)
		return (first);
	return (last);
}

int find_index_2(t_list *list, int num, int b_max, int b_min)
{
	int index;
	int prec;
	int succ;

	if (!list)
		return (0);
	if (!list->next)
	{
		if (num > *(int *)(list->data))
			return (0);
		return (1);
	}
	prec = *((int *)(ft_lstlast(list)->data));
	index = 0;
	while (list)
	{
		succ = *((int *)(list->data));
		if ((prec > num && (num > succ || succ == b_max)) || (num > succ && (prec > num || prec == b_min)))
			break ;
		prec = succ;
		index++;
		list = list->next;
	}
	return (index);
}

void insert_in_b(t_list **a, t_list **b, int size)
{
	int index;
	int b_max;
	int b_min;

	b_max = find_max(*b);
	b_min = find_min(*b);
	index = find_index_2(*b, *((int *)((*a)->data)), b_max, b_min);
	if (index <= (size / 2))
		exec_and_display("rb", NULL, b, index - 1);
	else
		exec_and_display("rrb", NULL, b, (size - index));
	exec_and_display("pb", a, b, 1);
	if (index <= (size / 2) && index != 0)
			exec_and_display("sb", NULL, b, 1);
}

void sort_n(t_list **a, t_list **b)
{
	int median;
	int a_size;
	int b_size;
	int quicker;

	median = (find_max(*a) + find_min(*a)) / 2;
	a_size = ft_lstsize(*a);
	b_size = ft_lstsize(*b);

	while (1)
	{
		quicker = find_quicker(*a, median, a_size);
		if (quicker == -1)
			break ;
		if (quicker <= a_size / 2)
			exec_and_display("ra", a, NULL, quicker);
		else
			exec_and_display("rra", a, NULL, a_size - quicker);
		insert_in_b(a, b, b_size++);
		a_size--;
	}
}