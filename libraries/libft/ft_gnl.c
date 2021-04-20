/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiordan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:19:10 by mgiordan          #+#    #+#             */
/*   Updated: 2021/03/17 17:19:13 by mgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strchr(char c, char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
	{
		if (str[ret] == c)
			return (ret);
		ret++;
	}
	return (-1);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*rslt;
	int		i;

	rslt = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	i = 0;
	while (*str1)
		rslt[i++] = *str1++;
	while (*str2)
		rslt[i++] = *str2++;
	rslt[i] = 0;
	return (rslt);
}

int	handle_return(char *total_read, char **line)
{
	if (total_read)
	{
		*line = total_read;
		return (1);
	}
	*line = ft_strdup("");
	return (0);
}

int	ft_gnl(int fd, char **line)
{
	char	tmp[2];
	char	*total_read;
	char	*safe;

	total_read = 0;
	while ((read(fd, tmp, 1)) > 0)
	{
		tmp[1] = 0;
		if (!total_read)
			total_read = ft_strdup(tmp);
		else
		{
			safe = total_read;
			total_read = ft_strjoin(total_read, tmp);
			free(safe);
		}
		if (ft_strchr('\n', total_read) >= 0)
		{
			total_read[ft_strchr('\n', total_read)] = 0;
			*line = total_read;
			return (1);
		}
	}
	return (handle_return(total_read, line));
}
