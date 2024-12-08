/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ouar <iel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:17:52 by iel-ouar          #+#    #+#             */
/*   Updated: 2024/12/08 20:35:06 by iel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

char	*ft_read_line(int fd, char *res, char *buf)
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
		if (!res)
			res = ft_strdup("");
		tmp = res;
		res = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (res);
}

char	*ft_set_line(char *line)
{
	size_t	i;
	char	*res;

	i = 0;
	while (line && line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	res = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (res && *res == '\0')
	{
		free(res);
		res = NULL;
	}
	line[i + 1] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(&res));
	buf = malloc((BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = ft_read_line(fd, res, buf);
	free(buf);
	buf = NULL;
	if (!line)
		return (ft_free(&res));
	res = ft_set_line(line);
	return (line);
}
