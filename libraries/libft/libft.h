/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiordan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 13:41:09 by mgiordan          #+#    #+#             */
/*   Updated: 2021/04/15 13:41:10 by mgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *data);
void	ft_lstadd_back(t_list **head, t_list *new);
void	ft_lstadd_front(t_list **head, t_list *new);
t_list	*ft_lstlast(t_list *head);
void	ft_lstclear(t_list **element);
t_list	*ft_lstlast(t_list *head);
int		ft_lstsize(t_list *head);
int		ft_is_num(const char *str);
int		ft_is_int(long n);
long	ft_atol(const char *num);
int		ft_gnl(int fd, char **line);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *str);
int		ft_strcmp(char *str1, char *str2);
char	**ft_split(char const *str, char del);
int		ft_strlcpy(char *dest, const char *src, int size);
void	ft_putnbr(long n);
int		ft_printf(const char *str, ...);

#endif
