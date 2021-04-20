/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiordan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:59:35 by mgiordan          #+#    #+#             */
/*   Updated: 2021/04/14 15:59:40 by mgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

/*
**void print_list(t_list *list)
**{
**	while (list)
**	{
**		printf("%d\n", *((int *)(list->data)));
**		list = list->next;
**	}
**}
*/

void	execute_cmnds(t_list *a, t_list *cmnds)
{
	t_list	*b;

	b = NULL;
	while (cmnds)
	{
		dispatcher(cmnds->data, &a, &b);
		cmnds = cmnds->next;
	}
	if (b || !check_sorted(a))
	{
		if (b)
			ft_lstclear(&b);
		write(1, "KO\n", 3);
	}
	else
		write(1, "OK\n", 3);
}

int	main(int narg, char *args[])
{
	t_list	*list;
	t_list	*cmnds;
	char	*tmp;

	if (narg == 1)
		return (1);
	list = parse_args(narg, args);
	if (!list)
		return (1);
	while (ft_gnl(0, &tmp) > 0)
		ft_lstadd_back(&cmnds, ft_lstnew(tmp));
	free(tmp);
	if (!check_cmnds(cmnds))
	{
		clear_and_error(list, cmnds);
		return (1);
	}
	execute_cmnds(list, cmnds);
	ft_lstclear(&cmnds);
	ft_lstclear(&list);
}
