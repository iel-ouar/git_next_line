/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ouar <iel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:17:52 by iel-ouar          #+#    #+#             */
/*   Updated: 2024/12/11 15:58:10 by iel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char **s)
{
	if (s && !*s)
	{
		free(*s);
		*s = NULL;
	}
	return (NULL);
}

static char	*ft_read_line(int fd, char *remainder, char *buf)
{
	ssize_t	read_line;
	char	*tmp;

	read_line = 1;
	while (read_line != 0)
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		tmp = remainder;
		remainder = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (remainder);
}

static char	*ft_set_line(char *line)
{
	size_t	i;
	char	*remainder;

	i = 0;
	while (line && line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	remainder = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (remainder && *remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	line[i + 1] = '\0';
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(&remainder));
	buf = malloc((BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_read_line(fd, remainder, buf);
	free(buf);
	buf = NULL;
	if (!line)
		return (ft_free(&remainder));
	remainder = ft_set_line(line);
	return (line);
}
