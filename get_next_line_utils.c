/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ouar <iel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:17:31 by iel-ouar          #+#    #+#             */
/*   Updated: 2024/12/08 16:50:18 by iel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = (char *)malloc(ft_strlen(s) + 1);
	if (!tmp)
		return (NULL);
	while (s[i])
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	size_t	j;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	tmp = (char *)malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		tmp[i++] = s2[j++];
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start >= l)
		return (ft_strdup(""));
	if (len > l - start)
		len = l - start;
	tmp = (char *)malloc (len + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((char )c == s[i])
			return ((char *)s + i);
		i++;
	}
	if ((char )c == '\0')
		return ((char *)s + i);
	return (NULL);
}
