/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchiodi <cchiodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:00:50 by cchiodi           #+#    #+#             */
/*   Updated: 2024/02/27 16:11:32 by cchiodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_str(int fd, char *str)
{
	char	buff[BUFFER_SIZE + 1];
	int		read_bytes;
	char	*linetot;

	read_bytes = 1;
	if (str != NULL)
		linetot = ft_strdup(str);
	while (!ft_strchr(linetot, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes <= 0)
			return (NULL);
		linetot = ft_strjoin(linetot, buff);
	}
	// free(buff);
	return (linetot);
}

void	savepointer(char *linetot, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ( linetot[i] != '\n' && linetot[i] != '\0')
		i++;
	i++;
	if (linetot[i] != '\n')
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
		str[0] = '\0';
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*linetot;
	static char str[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	linetot = ft_read_str(fd, str);
	if (linetot == NULL)
		return (NULL);
	line = ft_get_one_line(linetot);
	savepointer(linetot, str);
	free(linetot);
	return (line);
}
