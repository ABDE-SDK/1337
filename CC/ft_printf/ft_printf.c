/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:46:51 by asidki            #+#    #+#             */
/*   Updated: 2026/11/13 20:05:08 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_spec(const char **format, va_list ap)
{
	int	ret;

	(*format)++;
	if (!**format)
		return (-1);
	if (**format == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (**format == 'c')
		return (ft_putchr(va_arg(ap, int)));
	else if (**format == 'd' || **format == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (**format == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	else if (**format == 'X' || **format == 'x')
		return (ft_puthex(va_arg(ap, unsigned int), **format));
	else if (**format == 'p')
		return (ft_putptr(va_arg(ap, unsigned long)));
	else if (**format == '%')
		return (ft_putchr('%'));
	else
	{
		ret = ft_putchr('%');
		ret += ft_putchr(**format);
		return (ret);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		ret;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			ret = handle_spec(&format, ap);
		else
			ret = ft_putchr(*format);
		if (ret == -1)
		{
			va_end(ap);
			return (-1);
		}
		count += ret;
		format++;
	}
	va_end(ap);
	return (count);
}
