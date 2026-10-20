/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 20:51:16 by asidki            #+#    #+#             */
/*   Updated: 2026/10/20 22:44:32 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft"

void *calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	if (nmemb == 0 && nmemb < SIZE_MAX / size)
		return (NULL);
	
}
