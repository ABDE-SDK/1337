/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:31:23 by asidki            #+#    #+#             */
/*   Updated: 2026/10/22 11:36:29 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	if (start > s_len)
		ft_strdup("");
	if (len > s_len - start)
		len = s_len - start;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start, len);
	return (dest);
}
