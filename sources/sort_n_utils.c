#include "push_swap.h"

int	find_quicker(t_list *a, int *median, int last_sorted, int size)
{
	int	first;
	int	last;
	int	i;

	first = -1;
	last = -1;
	i = -1;
	while (++i < size)
	{
		if (*(int *)(a->data) <= *median && *(int *)(a->data) > last_sorted)
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
	if (last == -1 || first <= size - last)
		return (first);
	return (last);
}

int	calculate_moves(int b_index, int b_size, int a_index, int a_size)
{
	int	moves;

	if (b_index <= (b_size / 2))
		moves = b_index;
	else
		moves = b_size - b_index;
	if (a_index <= (a_size / 2))
		moves += a_index;
	else
		moves += a_size - a_index;
	return (moves);
}

int	find_lowest(t_list *a, t_list *b, int a_size, int b_size)
{
	int	min_moves;
	int	best_choice;
	int	current_moves;
	int	b_index;
	int	a_index;

	min_moves = 2147483647;
	b_index = 0;
	while (b)
	{
		a_index = find_index(a, *((int *)(b->data)));
		current_moves = calculate_moves(b_index, b_size, a_index, a_size);
		if (current_moves < min_moves)
		{
			min_moves = current_moves;
			best_choice = b_index;
		}
		b_index++;
		b = b->next;
	}
	return (best_choice);
}

void	push_back_to_a(t_list **a, t_list **b, int b_size)
{
	int	b_index;
	int	a_index;
	int	a_size;

	a_size = ft_lstsize(*a);
	while (*b)
	{
		b_index = find_lowest(*a, *b, a_size, b_size);
		if (b_index <= (b_size / 2))
			execute("rb", NULL, b, b_index);
		else
			execute("rrb", NULL, b, (b_size - b_index));
		a_index = find_index(*a, *((int *)((*b)->data)));
		if (a_index <= (a_size / 2))
			execute("ra", a, NULL, a_index - 1);
		else
			execute("rra", a, NULL, (a_size - a_index));
		execute("pa", a, b, 1);
		if (a_index && a_index <= (a_size / 2))
			execute("sa", a, NULL, 1);
		a_size++;
		b_size--;
	}
}

int	init_n_sorting(int **median, t_list *a, int *a_size)
{
	int	last_sorted;

	if (*median)
	{
		last_sorted = **median;
		**median = (find_max(a) + (**median + 1)) / 2;
	}
	else
	{
		last_sorted = -2147483648;
		(*median) = malloc(sizeof(int));
		**median = (find_max(a) + find_min(a)) / 2;
	}
	*a_size = ft_lstsize(a);
	return (last_sorted);
}
