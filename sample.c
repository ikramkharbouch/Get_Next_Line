/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:30:27 by ikrkharb          #+#    #+#             */
/*   Updated: 2019/04/16 16:47:33 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"

int		readlinewidth(int fd)
{
	char buff[2];
	size_t	nbread;

	(void) memset((void *) buff, 0, (size_t) 2);
	nbread = read(fd, (void *) buff, (size_t) 2);
	if ((int)nbread == -1 || (int)nbread == 0)
		return (-1);
	buff[1] = '\0';
	return (atoi(buff));
}

void	readandprintlines(int fd, size_t linewidth)
{
	char	*buff;
	size_t	nbread;

	buff = (char *)malloc((linewidth + 1) * sizeof(*buff));
	if (buff == NULL)
		return ;
	(void)memset((void *)buff, 0, linewidth + 1);
	while ((nbread = read(fd, (void *)buff, linewidth)) != 0)
	{
		printf("%s", buff);
		(void)memset((void *)buff, 0, linewidth);
	}
	free(buff);
	return ;
}

int		main(void)
{
	int		fd;
	int		linewidth;
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	linewidth = readlinewidth(fd);
	if (linewidth == -1 || linewidth == 0)
		return (-1);
	readandprintlines(fd, (size_t) linewidth);
	close(fd);
	return (0);
}


