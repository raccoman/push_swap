/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiordan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:39:46 by mgiordan          #+#    #+#             */
/*   Updated: 2021/04/15 13:39:48 by mgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *list)
{
	void	*tmp;

	if (!list || !list->next)
		return ;
	tmp = list->data;
	list->data = list->next->data;
	list->next->data = tmp;
}

void	push(t_list **list1, t_list **list2)
{
	t_list	*tmp;

	if (!(*list2))
		return ;
	tmp = *list2;
	*list2 = (*list2)->next;
	ft_lstadd_front(list1, tmp);
}

void	rotate(t_list **list)
{
	t_list	*tmp;

	if (!(*list) || !(*list)->next)
		return ;
	tmp = ft_lstlast(*list);
	tmp->next = *list;
	tmp = (*list)->next;
	(*list)->next = NULL;
	*list = tmp;
}

void	rev_rotate(t_list **list)
{
	t_list	*tmp;

	if (!(*list) || !(*list)->next)
		return ;
	tmp = ft_lstlast(*list);
	tmp->next = *list;
	while ((*list)->next != tmp)
		*list = (*list)->next;
	(*list)->next = NULL;
	*list = tmp;
}
