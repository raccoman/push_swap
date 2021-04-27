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

void	print_lists(t_list *a, t_list *b)
{
	printf("%7s    │%5s\n  ─────────│─────────\n", "A", "B");
	while (a || b)
	{
		if (a && b)
			printf("%9d  │%7d\n", *((int *)(a->data)), *((int *)(b->data)));
		else if (a)
			printf("%9d  │\n", *((int *)(a->data)));
		else
			printf("      |%7d\n", *((int *)(b->data)));
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	ft_printf("\n");
}

void	print_cmd(char *cmd)
{
	int	len;

	len = ft_strlen(cmd);
	if (cmd[len - 1] == 'a')
		ft_printf("  \033[0;35m%s\033[0m\n", cmd);
	else
		ft_printf("  \033[0;36m%s\033[0m\n", cmd);
}

void	execute_cmds(t_list **a, t_list *cmds, int *flags)
{
	t_list	*b;

	b = NULL;
	if (*flags)
		print_lists(*a, b);
	while (cmds)
	{
		if (flags[1])
			print_cmd(cmds->data);
		dispatcher(cmds->data, a, &b);
		cmds = cmds->next;
		if (*flags)
			print_lists(*a, b);
		if (flags[2] && cmds)
			sleep(4);
	}
	if (b || !check_sorted(*a))
	{
		if (b)
			ft_lstclear(&b);
		ft_printf("\033[0;31mKO\033[0m\n");
	}
	else
		ft_printf("\033[0;32mOK\033[0m\n");
}

t_list	*parse_args_flags(int argc, char *argv[], int *flags)
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
		else if (!is_flag(argv[i], flags))
			return (clear_and_error(list, NULL, argc, argv));
	}
	return (check_duplicates(list, argc, argv));
}

int	main(int argc, char *argv[])
{
	t_list	*list;
	t_list	*cmds;
	char	*tmp;
	int		flags[4];

	if (argc == 1)
		return (1);
	reset_flags(flags);
	list = parse_args_flags(argc, argv, flags);
	if (!list)
		return (1);
	cmds = NULL;
	while (ft_gnl(0, &tmp) > 0)
		ft_lstadd_back(&cmds, ft_lstnew(tmp));
	free(tmp);
	if (!check_cmds(cmds))
	{
		clear_and_error(list, cmds, argc, argv);
		return (1);
	}
	execute_cmds(&list, cmds, flags);
	if (flags[3])
		print_moves(cmds);
	ft_lstclear(&cmds);
	ft_lstclear(&list);
}
