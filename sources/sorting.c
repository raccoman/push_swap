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

int find_index(t_list *list, int num)
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
	return (i);
}

void insert_sorted(t_list **a, t_list **b, int size)
{
	int index;

	while (*b)
	{
		index = find_index(*a, *((int *)((*b)->data)));
		if (index <= (size / 2))
			exec_and_display("ra", a, NULL, index - 1);
		else
			exec_and_display("rra", a, NULL, (size - index));
		exec_and_display("pa", a, b, 1);
		if (index && index <= (size / 2))
			exec_and_display("sa", a, NULL, 1);
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

static int find_max(t_list *list)
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

static int find_min(t_list *list)
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

int find_quicker(t_list *a, int median, int last_sorted, int size)
{
	int first = -1;
	int last = -1;
	int i = -1;

	while (++i < size)
	{
		if (*(int *)(a->data) <= median && *(int *)(a->data) > last_sorted)
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
#include <stdio.h>

int find_lowest(t_list *a, t_list *b, int a_size, int b_size)
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
        if (b_index <= (b_size / 2))
            current_moves = b_index;
		else
            current_moves = b_size - b_index;
		if (a_index <= (a_size / 2))
            current_moves += a_index;
		else
            current_moves += a_size - a_index;
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

/*static void print_list(t_list *list)
{
	while (list)
	{
		printf("%d\n", *((int *)(list->data)));
		list = list->next;
	}
}*/

void push_back_to_a(t_list **a, t_list **b, int a_size, int b_size)
{
	int index_b;
	int index_a;

	while (*b)
	{
        index_b = find_lowest(*a, *b, a_size, b_size);
        if (index_b <= (b_size / 2))
            exec_and_display("rb", NULL, b, index_b);
        else
            exec_and_display("rrb", NULL, b, (b_size - index_b));
        index_a = find_index(*a, *((int *) ((*b)->data)));
        if (index_a <= (a_size / 2))
            exec_and_display("ra", a, NULL, index_a - 1);
        else
            exec_and_display("rra", a, NULL, (a_size - index_a));
        exec_and_display("pa", a, b, 1);
		if (index_a && index_a <= (a_size / 2))
			exec_and_display("sa", a, NULL, 1);
        a_size++;
        b_size--;
    }
}

void sort_n(t_list **a, t_list **b)
{
	static int *median;
	int last_sorted;
	int a_size;
	int b_size;
	int quicker;
	
	if (median)
	{
		last_sorted = *median;
		*median = (find_max(*a) + (*median + 1)) / 2;
	}
	else
	{
		last_sorted = -2147483648;
		median = malloc(sizeof(int *));
		*median = (find_max(*a) + find_min(*a)) / 2;
	}
	a_size = ft_lstsize(*a);
	b_size = ft_lstsize(*b);

	while (1)
	{
		quicker = find_quicker(*a, *median, last_sorted, a_size);
		if (quicker == -1)
			break ;
		if (quicker <= a_size / 2)
			exec_and_display("ra", a, NULL, quicker);
		else
			exec_and_display("rra", a, NULL, a_size - quicker);
		exec_and_display("pb", a, b, 1);
		a_size--;
		b_size++;
	}
	if (last_sorted == -2147483648)
	{
		exec_and_display("pa", a, b, 1);
		b_size--;
		a_size++;
	}
	push_back_to_a(a, b, a_size, b_size);
}