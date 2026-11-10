/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:46:51 by asidki            #+#    #+#             */
/*   Updated: 2026/11/10 15:59:45 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				count += ft_putstr(va_arg(ap, char *));
			else if (format[i] == 'c')
				count += ft_putchr(va_arg(ap, int));
			else if (format[i] ==  'd' || format[i] == 'i')
				count += ft_putnbr(va_arg(ap, int));
			else if (format[i] == 'u')
				count += ft_putunbr(va_arg(ap, unsigned int));
			else if (format[i] == 'X' || format[i] == 'x')
				count += ft_puthex(va_arg(ap, unsigned int), format[i]);
			// else if (format[i] == 'p')
			// 	count += ft_putptr(va_arg(ap, unsigned long));
			else if (format[i] == '%')
				count += ft_putchr('%');
		}
		else
			count += ft_putchr(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}



 int main()
 {
  	// int a = ft_printf("%%hi this %s has %d like %s and that a facking %x pointer", "", 21, NULL);
  	// printf("\n\n");
 //
  	int x = 4;
  	int *p = &x;
 //
  	// int b = printf("%%hi this %p has %d like %s and that a facking %x pointer", p);
  	// printf("\n %d characters\n\n%d characters", b);
 //
	int a = printf("%p", p);
  	printf("\n%d", a);
  }
