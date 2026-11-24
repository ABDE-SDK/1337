/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 18:06:10 by asidki            #+#    #+#             */
/*   Updated: 2026/11/24 11:59:49 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stddef.h>

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

	buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = read(node->fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		old_stash = node->stash;
		node->stash = ft_strjoin(old_stash, buf);
		free(old_stash);
		if (!node->stash || ft_strchr(buf, '\n'))
			break ;
		bytes_read = read(node->fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (bytes_read == -1 || !node->stash)
		return (NULL);
	return (node->stash);
}

char	*clean_line_and_save_remain(char **stash)
{
	char	*line;
	char	*clean_line;
	size_t	i;

	i = 0;
	if (!*stash || !**stash)
		return (NULL);
	line = *stash;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] != '\n')
		i++;
	clean_line = ft_substr(line, 0, i);
	if (!clean_line)
		return (NULL);
	free(*stash);
	*stash = ft_substr(line, i, ft_strlen(line) - i);
	free(line);
	if (!*stash)
		return (NULL);
	return (clean_line);
}

char	*get_next_line(int fd)
{
	static t_list	*head_stash;
	t_list			*fd_node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_node = get_node(&head_stash, fd);
	if (!fd_node)
		return (NULL);
	fd_node->stash = read_until_nl(fd_node);
	if (!fd_node->stash)
	{
		free_node(fd, &head_stash);
		return (NULL);
	}
	line = clean_line_and_save_remain(&fd_node->stash);

	return (line);
}
