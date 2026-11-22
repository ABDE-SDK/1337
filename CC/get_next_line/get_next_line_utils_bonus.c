/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 09:46:26 by asidki            #+#    #+#             */
/*   Updated: 2026/11/22 15:09:48 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	char	*end;

	if (!str)
		return (0);
	end = str;
	while (*end)
		end++;
	return (end - str);
}

char	*ft_strchr(char *str, char c)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	char	*temp;

	if (!str)
		return (NULL);
	dup = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	temp = dup;
	while (*str)
		*temp++ = *str++;
	*temp = '\0';
	return (dup);
}

char	*ft_strjoin(char *old_stash, char *new_stash)
{
	char	*new_str;
	char	*temp;

	if (!old_stash && !new_stash)
		return (NULL);
	if (!old_stash)
		return (ft_strdup(new_stash));
	if (!new_stash)
		return (ft_strdup(old_stash));
	new_str = malloc(sizeof(char) * (ft_strlen(old_stash)
				+ ft_strlen(new_stash) + 1));
	if (!new_str)
		return (NULL);
	temp = new_str;
	while (*old_stash)
		*temp++ = *old_stash++;
	while (*new_stash)
		*temp++ = *new_stash++;
	*temp = '\0';
	return (new_str);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	if (!str)
		return (NULL);
	s_len = ft_strlen(str);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = str[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
