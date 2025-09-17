/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_internal.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 21:19:46 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/17 06:06:30 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_INTERNAL_H
# define GET_NEXT_LINE_INTERNAL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4069
# endif

# include <unistd.h>
# include <stdlib.h>

typedef unsigned char	t_byte;
typedef unsigned int	t_uint;

char	*gnl_append(char *dst, const char *src);
char	*gnl_pop(char **repo);
char	*gnl_substr(const char *s, t_uint start_index, t_uint len);
t_uint	gnl_strlen(const char *s);
int		gnl_char_index(char *str, char c);

#endif
