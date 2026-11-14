/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:53:57 by asidki            #+#    #+#             */
/*   Updated: 2026/11/14 09:26:27 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	count;
	int	ret;

	count = 0;
	if (n >= 10)
	{
		ret = ft_putunbr(n / 10);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchr(n % 10 + '0');
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
