/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 07:45:22 by asidki            #+#    #+#             */
/*   Updated: 2026/11/11 16:23:30 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		count;
	int		ret;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		nb = -nb;
		if (ft_putchr('-') == -1)
			return (-1);
		count++;
	}
	if (nb >= 10)
	{
		ret = ft_putnbr(nb / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchr(nb % 10 + '0');
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
