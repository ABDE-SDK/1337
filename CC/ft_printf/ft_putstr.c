/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 14:19:50 by asidki            #+#    #+#             */
/*   Updated: 2026/11/10 15:15:01 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	while (str[count])
		count++;
	if (write(1, str, count) == -1)
		return (-1);
	return (count);
}
