/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 10:57:11 by asidki            #+#    #+#             */
/*   Updated: 2026/11/11 14:12:44 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long nbr, char spec)
{
	int		count;
	int		ret;
	char	*base;

	count = 0;
	if (spec == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ret = ft_puthex(nbr / 16, spec);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchr(base[nbr % 16]);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
