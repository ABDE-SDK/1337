/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 07:45:22 by asidki            #+#    #+#             */
/*   Updated: 2026/11/08 08:16:31 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		if ((write(1, "-2147483648", 12)) == -1)
			return (-1);
		count = 11;
		return (count);
	}
	if (n < 0)
	{
		n = -n;
		count += ft_putchr('-');
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
	}
	count += ft_putchr(n % 10 + '0');
	return (count);
}
