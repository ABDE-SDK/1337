/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:06:10 by asidki            #+#    #+#             */
/*   Updated: 2026/11/23 15:15:33 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

t_list	*get_node(t_list **head_stash, int fd)
{
	t_list	*curr;
	t_list	*new_node;

	curr = *head_stash;
	while (curr)
	{
		if (curr->fd == fd)
			return (curr);
		curr = curr->next;
	}
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->stash = NULL;
	new_node->next = *head_stash;
	*head_stash = new_node;
	return (new_node);
}

void	free_node(int fd, t_list **head_stash)
{
	t_list	*curr;
	t_list	*prev;

	curr = *head_stash;
	prev = NULL;
	while (curr)
	{
		if (curr->fd == fd)
		{
			if (prev == NULL)
				*head_stash = curr->next;
			else
				prev->next = curr->next;
			free(curr->stash);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

char	*read_until_nl(t_list *node)
{
	char	*buf;
	char	*old_stash;
	ssize_t	bytes_read;

	buf = malloc(sizeof(char) * (size_t)BUFFER_SIZE);
	if (!buf)
		return (NULL);
	bytes_read = read(node->fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		old_stash = node->stash;
		node->stash = ft_strjoin(old_stash, buf);
		free(old_stash);
		if (node->stash)
			free_node();
	}
}

char	*get_next_line(int fd)
{
	static t_list	*head_stash;
	t_list			*fd_node;
	char			*line;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	fd_node = get_node(&head_stash, fd);
	if (!fd_node)
		return (NULL);
	fd_node->stash = read_until_nl(fd_node);

	return (line);
}
