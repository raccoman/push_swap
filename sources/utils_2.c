#include "push_swap.h"

int	count_args(char **argv, int *i)
{
	int	count;

	count = 0;
	while (argv[count])
		count++;
	(*i)--;
	return (count);
}

t_list	*parse_args(int argc, char *argv[])
{
	t_list	*list;
	int		i;
	int		*data;
	long	tmp;

	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = count_args(argv, &i);
	}
	list = NULL;
	while (++i < argc)
	{
		if (ft_is_num(argv[i]) && ft_is_int(ft_atol(argv[i])))
		{
			tmp = ft_atol(argv[i]);
			data = malloc(sizeof(int));
			*data = (int)tmp;
			ft_lstadd_back(&list, ft_lstnew(data));
		}
		else
			return (clear_and_error(list, NULL, argc, argv));
	}
	return (check_duplicates(list, argc, argv));
}

void	dispatcher(char *cmd, t_list **a, t_list **b)
{
	if (!ft_strcmp(cmd, "sa") || !ft_strcmp(cmd, "ss"))
		swap(*a);
	if (!ft_strcmp(cmd, "sb") || !ft_strcmp(cmd, "ss"))
		swap(*b);
	if (!ft_strcmp(cmd, "pa"))
		push(a, b);
	if (!ft_strcmp(cmd, "pb"))
		push(b, a);
	if (!ft_strcmp(cmd, "ra") || !ft_strcmp(cmd, "rr"))
		rotate(a);
	if (!ft_strcmp(cmd, "rb") || !ft_strcmp(cmd, "rr"))
		rotate(b);
	if (!ft_strcmp(cmd, "rra") || !ft_strcmp(cmd, "rrr"))
		rev_rotate(a);
	if (!ft_strcmp(cmd, "rrb") || !ft_strcmp(cmd, "rrr"))
		rev_rotate(b);
}

void	execute(char *cmd, t_list **a, t_list **b, int times)
{
	int	i;

	i = -1;
	while (++i < times)
	{
		write(1, cmd, ft_strlen(cmd));
		write(1, "\n", 1);
		dispatcher(cmd, a, b);
	}
}
