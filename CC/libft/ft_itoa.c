/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 14:31:45 by asidki            #+#    #+#             */
/*   Updated: 2026/10/25 15:18:47 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_length(long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*dest;
	size_t	len;
	long	nbr;

	nbr = n;
	len = ft_length(nbr);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest[len] = '\0';
	if (nbr == 0)
		dest[0] = '0';
	if (nbr < 0)
	{
		nbr = -nbr;
		dest[0] = '-';
	}
	while (nbr != 0)
	{
		dest[--len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (dest);
}
