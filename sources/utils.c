/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiordan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:39:53 by mgiordan          #+#    #+#             */
/*   Updated: 2021/04/15 13:39:59 by mgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*clear_and_error(t_list *list, t_list *list2, int argc, char **argv)
{
	int	i;

	write(2, "Error\n", 6);
	ft_lstclear(&list);
	ft_lstclear(&list2);
	if (argc == 2)
	{
		i = 0;
		while (argv[i++])
			free(argv[i - 1]);
		free(argv);
	}
	return (NULL);
}

int	is_cmd(char *cmd)
{
	return (!ft_strcmp(cmd, "sa") || !ft_strcmp(cmd, "ss")
		|| !ft_strcmp(cmd, "pa") || !ft_strcmp(cmd, "pb")
		|| !ft_strcmp(cmd, "sb") || !ft_strcmp(cmd, "ra")
		|| !ft_strcmp(cmd, "rb") || !ft_strcmp(cmd, "rr")
		|| !ft_strcmp(cmd, "rra") || !ft_strcmp(cmd, "rrb")
		|| !ft_strcmp(cmd, "rrr"));
}

int	check_cmds(t_list *cmds)
{
	while (cmds)
	{
		if (!is_cmd(cmds->data))
			return (0);
		cmds = cmds->next;
	}
	return (1);
}

t_list	*check_duplicates(t_list *list, int argc, char **argv)
{
	t_list	*tmp;
	t_list	*safe;
	int		i;

	safe = list;
	while (list)
	{
		tmp = list->next;
		while (tmp)
		{
			if (*((int *)(list->data)) == *((int *)(tmp->data)))
				return (clear_and_error(safe, NULL, argc, argv));
			tmp = tmp->next;
		}
		list = list->next;
	}
	if (argc == 2)
	{
		i = 0;
		while (argv[i++])
			free(argv[i - 1]);
		free(argv);
	}
	return (safe);
}

int	check_sorted(t_list *a)
{
	int	max;
	int	min;

	max = find_max(a);
	min = find_min(a);
	while (a && a->next)
	{
		if ((!(*((int *)(a->data)) == max && *((int *)(a->next->data)) == min))
			&& *((int *)(a->data)) > *((int *)(a->next->data)))
			return (0);
		a = a->next;
	}
	return (1);
}
