/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 10:41:33 by asidki            #+#    #+#             */
/*   Updated: 2026/11/19 16:55:03 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_stash(int fd, char *stash)
{
	char	*buf;
	char	*old;
	ssize_t	bytes_read;

	buf = malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (!buf)
	{
		free(stash);
		return (NULL);
	}
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf)
			free(stash);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		old = stash;
		stash = ft_strjoin(old, buf);
	}
	return (stash);
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
	line = ft_strdup(stash);
	return (line);
}

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
	int fd = open("test.txt", O_RDWR | O_TRUNC);
	char str[] = "hello\nworld\n";

	write(fd, str, sizeof(str));

	char *s = get_next_line(fd);
	printf("\n the line from GNL:\n%s", s);
}
