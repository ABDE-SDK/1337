/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 18:18:31 by asidki            #+#    #+#             */
/*   Updated: 2026/10/18 22:02:50 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (n == 0)
		return (dest);
	if (d > s)
		while (n--)
			d[n] = s[n];
	else if (d < s)
		while (n--)
			*d++ = *s++;
	return (dest);
}
