/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_internal.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:47:05 by abazzoun          #+#    #+#             */
/*   Updated: 2025/09/04 12:49:13 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEXT_LINE_INTERNAL_H
# define NEXT_LINE_INTERNAL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4069
# endif

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef unsigned char	t_byte;
typedef unsigned int	t_uint;

char	*ft_gnl_str_append(char *dst, const char *src);
char	*ft_gnl_line_pop(char **repo);
char	*ft_gnl_substr(const char *s, t_uint start_index, t_uint len);
t_uint	ft_gnl_strlen(const char *s);
int		ft_gnl_char_index(char *str, char c);

#endif
