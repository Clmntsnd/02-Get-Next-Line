/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:56:37 by csenand           #+#    #+#             */
/*   Updated: 2022/11/23 15:15:26 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_save(char *stock)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
		return (ft_free(stock));
	ret = malloc((ft_strlen(stock) - i) + 1);
	if (!ret)
		return (NULL);
	i++;
	j = 0;
	while (stock && stock[i])
		ret[j++] = stock[i++];
	ret[j] = 0;
	free(stock);
	stock = NULL;
	return (ret);
}

char	*ft_read_and_stock(int fd, char *stock)
{
	int		read_bytes;
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	read_bytes = -1;
	while ((ft_strchr(stock, '\n') == 0 || !stock) && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(stock);
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = 0;
		stock = ft_strjoin(stock, buff);
		if (!stock)
			return (ft_free(buff));
	}
	free(buff);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	stock[fd] = ft_read_and_stock(fd, stock[fd]);
	if (!stock[fd])
		return (ft_free(stock[fd]));
	line = ft_substr(stock[fd], '\n');
	stock[fd] = ft_save(stock[fd]);
	if (!line)
		return (ft_free(stock[fd]));
	return (line);
}

/*
#include <stdio.h>
#define RED    "\x1B[31m"
#define GRN    "\x1B[32m"
#define YEL    "\x1B[33m"
#define BLU    "\x1B[34m"
#define MAG    "\x1B[35m"
#define CYN    "\x1B[36m"
#define WHT    "\x1B[37m"
#define RESET  "\x1B[0m"
#define CLE    "\e[1;1H\e[2J"

void	*xfree(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

int	main(void)
{
	int		fd[3];
	char	*tmp[4];
	int		i;

	i = 0;
	fd[0] = open("test.txt", O_RDONLY);
	fd[1] = open("test2.txt", O_RDONLY);
	fd[2] = open("test3.txt", O_RDONLY);
	do
	{
		tmp[0] = get_next_line(fd[0]);
		tmp[1] = get_next_line(fd[1]);
		tmp[2] = get_next_line(fd[2]);
		printf("time call -- %d\n", ++i);
		if (tmp[0])
			printf(BLU"[fd-1]"WHT" = %s\n", tmp[0]);
		xfree(tmp[0]);
		if (tmp[1])
			printf(RED"[fd-2]"WHT" = %s\n", tmp[1]);
		xfree(tmp[1]);
		if (tmp[2])
			printf(GRN"[fd-3]"WHT" = %s\n", tmp[2]);
		xfree(tmp[2]);
	} while (tmp[0] != NULL || tmp[1] != NULL || tmp[2] != NULL);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
}
*/