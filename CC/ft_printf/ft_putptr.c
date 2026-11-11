/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:55:25 by asidki            #+#    #+#             */
/*   Updated: 2026/11/11 13:51:43 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long ptr)
{
	int	count;
	int	ret;

	if (!ptr)
		return (ft_putstr("(nil)"));
	ret = ft_putstr("0x");
	if (ret == -1)
		return (-1);
	count = ret;
	ret = ft_puthex(ptr, 'x');
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}
