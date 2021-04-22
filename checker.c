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

void	execute_cmds(t_list *a, t_list *cmds)
{
	t_list	*b;

	b = NULL;
	while (cmds)
	{
		dispatcher(cmds->data, &a, &b);
		cmds = cmds->next;
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

int	main(int argc, char *argv[])
{
	t_list	*list;
	t_list	*cmds;
	char	*tmp;

	if (argc == 1)
		return (1);
	list = parse_args(argc, argv);
	if (!list)
		return (1);
	while (ft_gnl(0, &tmp) > 0)
		ft_lstadd_back(&cmds, ft_lstnew(tmp));
	free(tmp);
	if (!check_cmds(cmds))
	{
		clear_and_error(list, cmds);
		return (1);
	}
	execute_cmds(list, cmds);
	ft_lstclear(&cmds);
	ft_lstclear(&list);
}
