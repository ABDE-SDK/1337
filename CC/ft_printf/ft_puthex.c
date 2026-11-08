/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 10:57:11 by asidki            #+#    #+#             */
/*   Updated: 2026/11/08 11:12:44 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int nbr, char spec)
{
	int		count;
	char	*base;

	count = 0;
	if (spec == 'X')
		base = "0123456789ABCDEF";
	if (spec == 'x')
		base = "0123456789abcdef";
	if (nbr >= 16)
		count += ft_puthex(nbr / 16, spec);
	count += ft_putchr(base[nbr % 16]);
	return (count);
}
