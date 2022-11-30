/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:24:05 by csenand           #+#    #+#             */
/*   Updated: 2022/11/30 15:08:23 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/*	get_next_line.c	*/

char	*get_next_line(int fd);
char	*ft_save(char *stock);
char	*ft_read_and_stock(int fd, char *stock);
char	*get_next_line(int fd);

/*	get_next_line_utils.c	*/

void	*ft_free(void *p);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *save, int c);

#endif