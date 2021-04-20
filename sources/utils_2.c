#include "push_swap.h"

t_list	*parse_args(int narg, char *args[])
{
	t_list	*list;
	int		i;
	int		*data;
	long	tmp;

	list = NULL;
	i = 0;
	while (++i < narg)
	{
		if (ft_is_num(args[i]) && ft_is_int(ft_atol(args[i])))
		{
			tmp = ft_atol(args[i]);
			data = malloc(sizeof(int));
			*data = (int)tmp;
			ft_lstadd_back(&list, ft_lstnew(data));
		}
		else
			return (clear_and_error(list, NULL));
	}
	return (check_duplicates(list));
}

void	dispatcher(char *cmnd, t_list **a, t_list **b)
{
	if (!ft_strcmp(cmnd, "sa") || !ft_strcmp(cmnd, "ss"))
		swap(*a);
	if (!ft_strcmp(cmnd, "sb") || !ft_strcmp(cmnd, "ss"))
		swap(*b);
	if (!ft_strcmp(cmnd, "pa"))
		push(a, b);
	if (!ft_strcmp(cmnd, "pb"))
		push(b, a);
	if (!ft_strcmp(cmnd, "ra") || !ft_strcmp(cmnd, "rr"))
		rotate(a);
	if (!ft_strcmp(cmnd, "rb") || !ft_strcmp(cmnd, "rr"))
		rotate(b);
	if (!ft_strcmp(cmnd, "rra") || !ft_strcmp(cmnd, "rrr"))
		rev_rotate(a);
	if (!ft_strcmp(cmnd, "rrb") || !ft_strcmp(cmnd, "rrr"))
		rev_rotate(b);
}