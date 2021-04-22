/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiordan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:40:06 by mgiordan          #+#    #+#             */
/*   Updated: 2021/04/21 16:39:18 by mgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>

# include "./libraries/libft/libft.h"

void	swap(t_list *list);
void	push(t_list **list1, t_list **list_2);
void	rotate(t_list **list);
void	rev_rotate(t_list **list);

void	*clear_and_error(t_list *list, t_list *list2);
int		is_cmnd(char *cmnd);
int		check_cmnds(t_list *cmnds);
t_list	*check_duplicates(t_list *list);
int		check_sorted(t_list *a);

t_list 	*parse_args(int narg, char *args[]);
void	dispatcher(char *cmnd, t_list **a, t_list **b);
void	exec_and_display(char *cmnd, t_list **a, t_list **b, int times);

void	sort_2(t_list *a);
void	sort_3(t_list **a);
void	sort_4(t_list **a, t_list **b);
void	sort_5(t_list **a, t_list **b);
void	sort_n(t_list **a, t_list **b);

#endif
