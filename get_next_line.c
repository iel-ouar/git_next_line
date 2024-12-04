/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ouar <iel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:17:52 by iel-ouar          #+#    #+#             */
/*   Updated: 2024/12/04 18:22:42 by iel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*res;
	char	*buf;
	char	*line;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buf);
		free(res);
		buf = NULL;
		res = NULL;
		return (NULL);
	}
	if (!buf)
		return (NULL);
    
}