/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:17:51 by asidki            #+#    #+#             */
/*   Updated: 2026/10/24 15:05:35 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_words(char const *s, char c);
size_t	ft_length(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	len_words;
	size_t	len_word;
	size_t	i;

	if (!s)
		return (NULL);
	len_words = ft_words(s, c);
	words = malloc(sizeof(char *) * (wc + 1));
	if (!words)
		return (NULL);
	i = 0;
	while ((*s != '\0') && (i < len_words))
	{
		while (*s == c)
			s++;
		if (*s != c)
			len_word = ft_length(s, c);
		words[] = ft_substr(s, 0, len_word);
	}
}

size_t	ft_words(char const *s, char c)
{
	size_t	wc;
	size_t	i;

	wc = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			wc++;
		}
		while (s[i] != c)
			i++;
	}
	return (wc);
}

size_t	ft_length(char const *s, char c)
{
	size_t	len;

	len = 0;
	while ((s[len] != c) || (s[len] != '\0'))
		len++;
	return (len);

}
