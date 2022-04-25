/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoctori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:35:57 by ldoctori          #+#    #+#             */
/*   Updated: 2021/11/09 09:53:30 by ldoctori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char			*get_next_line(int fd);
char			*ft_strjoin(const char *str, const char *buff);
char			*ft_strchr(const char *s, int c);
unsigned int	ft_strlen(const char *str);
char			*ft_strdup(char *src);
char			*ft_strndup(char *src, int n);

#endif
