/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:27:35 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/17 06:27:46 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_internal.h"

t_uint	gnl_strlen(const char *s)
{
	t_uint	i;

	if (!s)
		return (0);
	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*gnl_substr(const char *s, t_uint start_index, t_uint sub_len)
{
	char	*sub;
	char	*ptr;

	sub = (char *)malloc(sizeof(*sub) * (sub_len + 1));
	if (!sub)
		return (NULL);
	ptr = sub;
	s += start_index;
	while (sub_len--)
		*ptr++ = *s++;
	*ptr = '\0';
	return (sub);
}

int	gnl_char_index(char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (*str)
	{
		if (*str == c)
			return (i);
		i++;
		str++;
	}
	return (-1);
}

char	*gnl_append(char *dst, const char *src)
{
	char	*join;
	char	*joinp;
	char	*dstp;
	int		dstlen;
	int		srclen;

	dstlen = gnl_strlen(dst);
	srclen = gnl_strlen(src);
	join = (char *)malloc(sizeof(*join) * (dstlen + srclen + 1));
	if (!join)
		return (NULL);
	joinp = join;
	dstp = dst;
	while (dstlen--)
		*joinp++ = *dstp++;
	while (srclen--)
		*joinp++ = *src++;
	*joinp = '\0';
	if (dst)
		free(dst);
	return (join);
}

char	*gnl_pop(char **repo)
{
	char	*str;
	char	*line;
	char	*rest;
	int		index;
	int		len;

	str = *repo;
	len = gnl_strlen(str);
	index = gnl_char_index(str, '\n');
	if (index == -1)
		index = len - 1;
	line = gnl_substr(str, 0, index + 1);
	if (!line)
		return (NULL);
	rest = gnl_substr(str, index + 1, len - index - 1);
	if (!rest)
		return (NULL);
	free(str);
	*repo = rest;
	return (line);
}
