/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asidki <asidki@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 13:09:15 by asidki            #+#    #+#             */
/*   Updated: 2026/11/22 09:59:33 by asidki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	char			*stash;
	struct s_list	*next;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line_bonus(int fd);

size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *old_stash, char *new_stash);
char	*ft_strdup(char *str);
char	*ft_substr(char *str, unsigned int start, size_t len);

#endif
