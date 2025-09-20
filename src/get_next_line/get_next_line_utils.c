/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:27:35 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/20 22:42:09 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_internal.h"

t_uint	gnl_strlen(const char *s)
{
	t_uint	i;

	if (s == NULL)
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
	if (sub == NULL)
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

	if (str == NULL)
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
	char	*append;
	char	*append_start;
	char	*dst_start;
	int		dst_len;
	int		src_len;

	dst_len = gnl_strlen(dst);
	src_len = gnl_strlen(src);
	append = (char *)malloc(sizeof(*append) * (dst_len + src_len + 1));
	if (append == NULL)
		return (NULL);
	append_start = append;
	dst_start = dst;
	while (dst_len--)
		*append++ = *dst++;
	while (src_len--)
		*append++ = *src++;
	*append = '\0';
	if (dst_start != NULL)
		free(dst_start);
	return (append_start);
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
	if (line == NULL)
		return (NULL);
	rest = gnl_substr(str, index + 1, len - index - 1);
	if (rest == NULL)
		return (NULL);
	free(str);
	*repo = rest;
	return (line);
}
