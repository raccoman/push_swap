#include "push_swap.h"

int count_moves(char *move, t_list *list)
{
	int c;

	c = 0;
	while (list)
	{
		if (!ft_strcmp(list->data, move))
			c++;
		list = list->next;
	}
	return (c);
}

void	print_moves(t_list *list)
{
	printf("+ ───────── FINAL REPORT ───────── +\n");
	printf("│ SA:  %3d\t\t\t   │\n", count_moves("sa", list));
	printf("│ SB:  %3d\t\t\t   │\n", count_moves("sb", list));
	printf("│ SS:  %3d\t\t\t   │\n", count_moves("ss", list));
	printf("│ PA:  %3d\t\t\t   │\n", count_moves("pa", list));
	printf("│ PB:  %3d\t\t\t   │\n", count_moves("pb", list));
	printf("│ RA:  %3d\t\t\t   │\n", count_moves("ra", list));
	printf("│ RB:  %3d\t\t\t   │\n", count_moves("rb", list));
	printf("│ RR:  %3d\t\t\t   │\n", count_moves("rr", list));
	printf("│ RRA: %3d\t\t\t   │\n", count_moves("rra", list));
	printf("│ RRB: %3d\t\t\t   │\n", count_moves("rrb", list));
	printf("│ RRR: %3d\t\t\t   │\n", count_moves("rrr", list));
	printf("│ \033[0;33mTotal operations: %d\033[0m\t\t   │\n", ft_lstsize(list));
	printf("+ ──────────────────────────────── +\n");
}

void	reset_flags(int *flags)
{
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	flags[3] = 0;
}