/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 11:40:56 by asidki            #+#    #+#             */
/*   Updated: 2026/10/22 22:18:56 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total = s1_len + s2_len + 1;
	dest = malloc(total * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, total);
	ft_strlcat(dest, s2, total);
	return (dest);
}
