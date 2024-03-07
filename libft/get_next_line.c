/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:24:16 by eagbomei          #+#    #+#             */
/*   Updated: 2024/02/26 11:42:50 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*next_plz(char *lines)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = lines;
	while (lines[i] != '\0' && lines[i] != '\n')
		i++;
	if (!lines[i])
	{
		free(lines);
		return (NULL);
	}
	i++;
	while (lines[i])
		line[j++] = lines[i++];
	line[j++] = '\0';
	return (line);
}

char	*append_line(char *lines, char *ret)
{
	char	*temp;

	temp = ft_strjoin(lines, ret);
	free(lines);
	return (temp);
}

static char	*find_line(char *lines)
{
	char	*retline;
	int		i;

	i = 0;
	if (!lines[i])
		return (NULL);
	while (lines[i] != '\0' && lines[i] != '\n')
		i++;
	if (lines[i] == '\n')
		i++;
	retline = ft_calloc(sizeof(char), i + 1);
	if (retline == NULL)
	{
		free(lines);
		return (NULL);
	}
	i = 0;
	while (lines[i] != '\0' && lines[i] != '\n')
	{
		retline[i] = lines[i];
		i++;
	}
	if (lines[i] != '\0' && lines[i] == '\n')
		retline[i++] = '\n';
	return (retline);
}

static char	*readfile(int fd, char *lines)
{
	ssize_t		bytes;
	char		ret[BUFFER_SIZE +1];

	if (!lines)
		lines = ft_calloc(1, 1);
	if (lines == NULL)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, ret, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		ret[bytes] = '\0';
		lines = append_line(lines, ret);
		if (lines == NULL || ft_strchr(ret, '\n'))
			break ;
	}
	return (lines);
}

char	*get_next_line(int fd)
{
	static char	*lines;
	char		*retstr;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free(lines);
		lines = NULL;
		return (NULL);
	}
	lines = readfile(fd, lines);
	if (lines == NULL || lines[0] == '\0')
	{
		free(lines);
		lines = NULL;
		return (NULL);
	}
	retstr = find_line(lines);
	if (retstr == NULL)
	{
		lines = NULL;
		return (NULL);
	}
	lines = next_plz(lines);
	return (retstr);
}
