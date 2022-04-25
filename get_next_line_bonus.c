/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 08:53:37 by ldoctori          #+#    #+#             */
/*   Updated: 2021/11/12 09:05:25 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_read(int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*str;
	int		rb;

	rb = read(fd, buff, BUFFER_SIZE);
	if (rb <= 0)
		return (NULL);
	buff[rb] = '\0';
	str = ft_strdup(buff);
	return (str);
}

char	*after_n(char **str)
{
	char	*ptr;
	char	*n;
	char	*pp;

	if (!ft_strlen(*str))
	{
		free(*str);
		*str = 0;
		return (0);
	}
	n = ft_strchr(*str, '\n');
	if (!n)
	{
		ptr = ft_strdup(*str);
		free(*str);
		*str = 0;
		return (ptr);
	}
	*n = '\0';
	n++;
	ptr = ft_strjoin(*str, "\n");
	pp = *str;
	*str = ft_strdup(n);
	free(pp);
	return (ptr);
}

void	before_n(char **str, int fd)
{
	char	*pp;
	char	*ptr;

	while (!ft_strchr(*str, '\n'))
	{
		ptr = get_read(fd);
		if (!ptr)
			break ;
		pp = *str;
		*str = ft_strjoin(*str, ptr);
		free(pp);
		free(ptr);
	}
}

char	*get_next_line(int fd)
{
	static char	*str[10240];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (str[fd] == 0)
	{
		str[fd] = get_read(fd);
		if (str[fd] == 0)
			return (NULL);
	}
	before_n(&str[fd], fd);
	return (after_n(&str[fd]));
}
