/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 10:41:33 by asidki            #+#    #+#             */
/*   Updated: 2026/11/22 19:10:29 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <unistd.h>

static char	*clean_and_null(char *ptr)
{
	free(ptr);
	return (NULL);
}

static char	*read_until_nl(int fd, char *stash)
{
	char	*buf;
	char	*old_stash;
	ssize_t	bytes_read;

	buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buf)
		return (clean_and_null(stash));
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		old_stash = stash;
		stash = ft_strjoin(old_stash, buf);
		free(old_stash);
		if (!stash)
			return (clean_and_null(buf));
		if (ft_strchr(buf, '\n'))
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (bytes_read == -1)
		return (clean_and_null(stash));
	return (stash);
}

static char	*get_clean_line(char *stash)
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
	stash = read_until_nl(fd, stash);
	if (!stash)
		return (NULL);
	line = get_clean_line(stash);
	stash = clean_stash(stash);
	return (line);
}
