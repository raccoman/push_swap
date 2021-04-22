#include "push_swap.h"

void	sort_2(t_list *a)
{
	if (*((int *)(a->data)) > *((int *)(a->next->data)))
		execute("sa", &a, NULL, 1);
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
		execute("sa", a, NULL, 1);
		top = *((int *)((*a)->data));
		middle = *((int *)((*a)->next->data));
	}
	if (top > middle && middle < bottom && bottom < top)
		execute("ra", a, NULL, 1);
	else if (top < middle && middle > bottom && bottom < top)
		execute("rra", a, NULL, 1);
}

void	sort_4(t_list **a, t_list **b)
{
	execute("pb", a, b, 1);
	sort_3(a);
	insert_sorted(a, b, 3);
}

void	sort_5(t_list **a, t_list **b)
{
	execute("pb", a, b, 2);
	sort_3(a);
	insert_sorted(a, b, 3);
}

int	*sort_n(t_list **a, t_list **b)
{
	static int	*median;
	int			last_sorted;
	int			a_size;
	int			quicker;

	last_sorted = init_n_sorting(&median, *a, &a_size);
	while (1)
	{
		quicker = find_quicker(*a, median, last_sorted, a_size);
		if (quicker == -1)
			break ;
		if (quicker <= a_size / 2)
			execute("ra", a, NULL, quicker);
		else
			execute("rra", a, NULL, a_size - quicker);
		execute("pb", a, b, 1);
		a_size--;
	}
	if (last_sorted == -2147483648)
		execute("pa", a, b, 1);
	push_back_to_a(a, b, ft_lstsize(*b));
	return (median);
}
