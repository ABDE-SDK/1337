/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 10:52:07 by asidki            #+#    #+#             */
/*   Updated: 2026/11/19 21:01:33 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#endif

char	*get_next_line(int fd);

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *old, char *new);
char	*ft_strchr(char *str, char c);
char	*ft_strdup(char *str);

#endif
