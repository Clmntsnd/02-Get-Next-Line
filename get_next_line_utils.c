/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:07:39 by csenand           #+#    #+#             */
/*   Updated: 2022/11/30 15:08:48 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (ft_free(s1));
		s1[0] = 0;
	}
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	join = malloc((i + j) + 1);
	if (!join)
		return (ft_free(s1));
	i = -1;
	j = -1;
	while (s1[++i])
		join[i] = s1[i];
	while (s2[++j])
		join[i + j] = s2[j];
	join[i + j] = 0;
	free(s1);
	return (join);
}

char	*ft_substr(char *save, int c)
{
	int		i;
	char	*buff;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != c)
		i++;
	if (save[i] == '\n')
		i++;
	buff = malloc(i + 1);
	if (!buff)
		return (NULL);
	i = -1;
	while (save[++i] && save[i] != c)
		buff[i] = save[i];
	if (save[i] == 10)
	{
		buff[i] = save[i];
		i++;
	}
	buff[i] = 0;
	return (buff);
}
