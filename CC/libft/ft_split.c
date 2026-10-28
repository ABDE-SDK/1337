/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:17:51 by asidki            #+#    #+#             */
/*   Updated: 2026/10/28 16:58:55 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words(char const *s, char c);
static size_t	ft_length(char const *s, char c);
static int		ft_fill(char **dest, char const *s, char c, size_t wc);
static void		ft_free(char **dest, size_t wc);

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	wc;

	if (!s)
		return (NULL);
	wc = ft_words(s, c);
	words = malloc(sizeof(char *) * (wc + 1));
	if (!words)
		return (NULL);
	if (!ft_fill(words, s, c, wc))
		return (0);
	return (words);
}

static int	ft_fill(char **dest, char const *s, char c, size_t wc)
{
	size_t	i;
	size_t	len_word;

	i = 0;
	while ((*s != '\0') && (i < wc))
	{
		while (*s == c)
			s++;
		if (*s != c)
			len_word = ft_length(s, c);
		dest[i] = ft_substr(s, 0, len_word);
		if (!dest[i])
		{
			ft_free(dest, i);
			return (0);
		}
		s += len_word;
		i++;
	}
	dest[i] = NULL;
	return (1);
}

static size_t	ft_words(char const *s, char c)
{
	size_t	wc;
	size_t	i;

	wc = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			wc++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wc);
}

static size_t	ft_length(char const *s, char c)
{
	size_t	len;

	len = 0;
	while ((s[len] != c) && (s[len] != '\0'))
		len++;
	return (len);
}

static void	ft_free(char **dest, size_t wc)
{
	while (wc > 0)
		wc--;
	free(dest[wc]);
	free(dest);
}
