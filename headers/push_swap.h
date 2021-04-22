/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiordan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:40:06 by mgiordan          #+#    #+#             */
/*   Updated: 2021/04/15 13:40:08 by mgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>

# include "../libraries/libft/libft.h"

void	swap(t_list *list);
void	push(t_list **list1, t_list **list_2);
void	rotate(t_list **list);
void	rev_rotate(t_list **list);

void	*clear_and_error(t_list *list, t_list *list2);
int		is_cmd(char *cmd);
int		check_cmds(t_list *cmds);
t_list	*check_duplicates(t_list *list);
int		check_sorted(t_list *a);

t_list	*parse_args(int argc, char *argv[]);
void	dispatcher(char *cmd, t_list **a, t_list **b);
void	execute(char *cmd, t_list **a, t_list **b, int times);

void	sort_2(t_list *a);
void	sort_3(t_list **a);
void	sort_4(t_list **a, t_list **b);
void	sort_5(t_list **a, t_list **b);
int		*sort_n(t_list **a, t_list **b);

int		init_n_sorting(int **median, t_list *a, int *a_size);
int		find_lowest(t_list *a, t_list *b, int a_size, int b_size);
int		find_quicker(t_list *a, int *median, int last_sorted, int size);
int		find_index_of_min(t_list *list);
int		find_index(t_list *list, int num);
int		find_max(t_list *list);
int		find_min(t_list *list);
void	insert_sorted(t_list **a, t_list **b, int size);
void	push_back_to_a(t_list **a, t_list **b, int b_size);

#endif
