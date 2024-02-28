/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchiodi <cchiodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:00:50 by cchiodi           #+#    #+#             */
/*   Updated: 2024/02/26 18:48:12 by cchiodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_str(int fd, char *str)
{
	char	*buff;
	int		read_bytes;

	if (str == NULL)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	read_bytes = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (!ft_strchr(str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		str = ft_strjoin(str, buff);
	}
	free(buff);
	if (str && *str)
		return (str);
	free(str);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char *str;

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_one_line(str);
	
	return (line);
}
