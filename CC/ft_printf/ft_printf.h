/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:51:41 by asidki            #+#    #+#             */
/*   Updated: 2026/11/08 12:02:19 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

int	ft_printf(const char *, ...);
int	ft_strlen(const char *str);
int	ft_putstr(const char *str);
int	ft_putnbr(int n);
int	ft_putchr(char c);
int	ft_puthex(unsigned int n, char spec);
int	ft_putunbr(unsigned int n);

#endif
