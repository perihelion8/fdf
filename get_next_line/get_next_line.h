/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazzoun <abazzoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:12:34 by abazzoun          #+#    #+#             */
/*   Updated: 2025/06/23 16:47:32 by abazzoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4069
# endif

# include <unistd.h>
# include <stdlib.h>

typedef unsigned char	t_byte;
typedef unsigned int	t_uint;

char	*get_next_line(int fd);
char	*ft_gnl_str_append(char *dst, const char *src);
char	*ft_gnl_line_pop(char **repo);
char	*ft_gnl_substr(const char *s, t_uint start_index, t_uint len);
t_uint	ft_gnl_strlen(const char *s);
int		ft_gnl_char_index(char *str, char c);

#endif
