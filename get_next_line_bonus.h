/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-bouz <zel-bouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:53:29 by zel-bouz          #+#    #+#             */
/*   Updated: 2022/11/16 19:42:45 by zel-bouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

// GET_NEXT_LINE_UTILS :

size_t	ft_strlen(const char *s);
int		ft_strchr(char *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);

// GET_NEXT_LINE :
char	*ft_get_line(char *saved);
char	*ft_get_left_str(char *saved);
char	*ft_read_from_file(int fd, char *saved);
char	*get_next_line(int fd);

#endif