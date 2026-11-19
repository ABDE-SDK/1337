/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:55:19 by asidki            #+#    #+#             */
/*   Updated: 2026/11/19 17:31:26 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

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
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	return (NULL);
}

char	*ft_strjoin(char *old, char *new)
{
	char	*new_str;
	char	*temp;

	if (!old && !new)
		return (NULL);
	if (!old)
		return (ft_strdup(new));
	if (!new)
		return (ft_strdup(old));
	new_str = malloc(sizeof(char) * (ft_strlen(old) + ft_strlen(new) + 1));
	if (!new_str)
		return (NULL);
	temp = new_str;
	while (*old)
	{
		*temp++ = *old++;
	}
	while (*new)
	{
		*temp++ = *new++;
	}
	*temp = '\0';
	return (new_str);
}
