/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchiodi <cchiodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:00:50 by cchiodi           #+#    #+#             */
/*   Updated: 2024/02/28 12:34:03 by cchiodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_str(int fd, char *str)
{
	char	buff[BUFFER_SIZE + 1];
	int		read_bytes;
	char	*linetot;

	if (str != NULL)
		linetot = ft_strdup(str);
	while (!ft_strchr(linetot, '\n'))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		buff[read_bytes] = '\0';
		if (read_bytes == 0 && *linetot == '\0')
		{
			free(linetot);
			return (NULL);
		}
		if (read_bytes == 0)
			return (linetot);
		if (read_bytes < 0)
		{
			free(linetot);
			return (NULL);
		}
		linetot = ft_strjoin(linetot, buff);
	}
	return (linetot);
}

void	savepointer(char *linetot, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (linetot[i] != '\n' && linetot[i] != '\0')
		i++;
	if (linetot[i] == '\n')
	{
		i++;
		while (linetot[i] != '\0')
		{
			str[j] = linetot[i];
			i++;
			j++;
		}
		str[j] = '\0';
	}
	else
	{
		i = 0;
		while (str[i] != '\0')
			str[i++] = '\0';
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*linetot;
	static char	str[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	linetot = ft_read_str(fd, str);
	if (linetot == NULL)
		return (NULL);
	line = ft_get_one_line(linetot);
	savepointer(linetot, str);
	free(linetot);
	return (line);
}
