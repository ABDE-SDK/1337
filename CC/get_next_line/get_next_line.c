/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 10:41:33 by asidki            #+#    #+#             */
/*   Updated: 2026/11/20 17:34:20 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clean_and_null(char *ptr)
{
	free(ptr);
	return (NULL);
}

static char	*read_and_stash(int fd, char *stash)
{
	char	*buf;
	char	*old;
	ssize_t	bytes_read;

	// Si stash contient déjà un '\\n' (issu du tour précédent), inutile de read()
	if (stash && ft_strchr(stash, '\n'))
		return (stash);
	buf = malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (clean_and_null(stash));
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return (clean_and_null(stash));
		}
		buf[bytes_read] = '\0';
		old = stash;
		stash = ft_strjoin(old, buf);
		free(old);
		if (!stash)
			return (clean_and_null(buf));
	}
	free(buf);
	return (stash);
}

static char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	return (line);
}

static char	*clean_stash(char *stash)
{
	char	*remain;
	size_t	i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	remain = ft_substr(stash, i + 1, ft_strlen(stash) - (i + 1));
	free(stash);
	if (remain && !*remain)
	{
		free(remain);
		return (NULL);
	}
	return (remain);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}
