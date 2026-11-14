/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:55:25 by asidki            #+#    #+#             */
/*   Updated: 2026/11/14 09:43:30 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *p)
{
	unsigned long	ptr;
	int				count;
	int				ret;
	
	if (!p)
		return (ft_putstr("(nil)"));
	ptr = (unsigned long)p;
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
