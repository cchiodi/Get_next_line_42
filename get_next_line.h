/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchiodi <cchiodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:01:07 by cchiodi           #+#    #+#             */
/*   Updated: 2024/02/27 18:01:03 by cchiodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read_str(int fd, char *str);
size_t	ft_strlen(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *str, char *buff);
char	*ft_get_one_line(char *linetot);
char	*ft_strdup(char *s);
void	savepointer(char *linetot, char *str);
#endif
