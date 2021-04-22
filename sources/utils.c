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

void	*clear_and_error(t_list *list, t_list *list2)
{
	write(2, "Error\n", 6);
	ft_lstclear(&list);
	ft_lstclear(&list2);
	return (NULL);
}

int	is_cmnd(char *cmnd)
{
	return (!ft_strcmp(cmnd, "sa") || !ft_strcmp(cmnd, "ss")
		|| !ft_strcmp(cmnd, "pa") || !ft_strcmp(cmnd, "pb")
		|| !ft_strcmp(cmnd, "sb") || !ft_strcmp(cmnd, "ra")
		|| !ft_strcmp(cmnd, "rb") || !ft_strcmp(cmnd, "rr")
		|| !ft_strcmp(cmnd, "rra") || !ft_strcmp(cmnd, "rrb")
		|| !ft_strcmp(cmnd, "rrr"));
}

int	check_cmnds(t_list *cmnds)
{
	while (cmnds)
	{
		if (!is_cmnd(cmnds->data))
			return (0);
		cmnds = cmnds->next;
	}
	return (1);
}

t_list	*check_duplicates(t_list *list)
{
	t_list	*tmp;
	t_list	*safe;

	safe = list;
	while (list)
	{
		tmp = list->next;
		while (tmp)
		{
			if (*((int *)(list->data)) == *((int *)(tmp->data)))
				return (clear_and_error(safe, NULL));
			tmp = tmp->next;
		}
		list = list->next;
	}
	return (safe);
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

int	check_sorted(t_list *a)
{
	int max;
	int min;

	max = find_max(a);
	min = find_min(a);
	while (a && a->next)
	{
		if ((!(*((int *)(a->data)) == max && *((int *)(a->next->data)) == min)) && *((int *)(a->data)) > *((int *)(a->next->data)))
			return (0);
		a = a->next;
	}
	return (1);
}
