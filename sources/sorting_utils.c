#include "push_swap.h"

void	insert_sorted(t_list **a, t_list **b, int size)
{
	int	index;

	while (*b)
	{
		index = find_index(*a, *((int *)((*b)->data)));
		if (index <= (size / 2))
			execute("ra", a, NULL, index - 1);
		else
			execute("rra", a, NULL, (size - index));
		execute("pa", a, b, 1);
		if (index && index <= (size / 2))
			execute("sa", a, NULL, 1);
		size++;
	}
}

int	find_index_of_min(t_list *list)
{
	int	min;
	int	index;
	int	i;

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

int	find_index(t_list *list, int num)
{
	int		start;
	int		i;
	t_list	*iter;

	start = find_index_of_min(list);
	iter = list;
	i = -1;
	while (++i < start)
		iter = iter->next;
	while (1)
	{
		if (*((int *)(iter->data)) > num)
			return (i);
		i++;
		iter = iter->next;
		if (!iter)
		{
			iter = list;
			i = 0;
		}
		if (i == start)
			return (start);
	}
}

int	find_max(t_list *list)
{
	int	max;

	max = -2147483648;
	while (list)
	{
		if ((*(int *)(list->data)) > max)
			max = (*(int *)(list->data));
		list = list->next;
	}
	return (max);
}

int	find_min(t_list *list)
{
	int	min;

	min = 2147483647;
	while (list)
	{
		if ((*(int *)(list->data)) < min)
			min = (*(int *)(list->data));
		list = list->next;
	}
	return (min);
}
