/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchiodi <cchiodi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:40:31 by cchiodi           #+#    #+#             */
/*   Updated: 2024/02/26 18:45:22 by cchiodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	b;
	int		i;

	b = c;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == b)
			return ((char *) str + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buff)
{
	size_t		i;
	size_t		j;
	char		*newstr;

	if (str == NULL || buff == NULL)
		return (NULL);
	newstr = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buff)) + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[j])
		newstr[i++] = str[j++];
	j = 0;
	while (buff[j])
		newstr[i++] = buff[j++];
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_get_one_line(char *str)
{
	int		i;
	char	*line;

	line = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
		line[i] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

