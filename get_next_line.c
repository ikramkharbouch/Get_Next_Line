/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:20:04 by ikrkharb          #+#    #+#             */
/*   Updated: 2019/04/18 22:56:55 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_newline(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	str = ft_strnew(len);
	i = 0;
	while (*str && *str != '\n')
	{
		str++;
		i++;
	}
	return (str - i);
}

int		get_next_line(const int fd, char **line)
{
	char	buff[BUFF_SIZE + 1];
	int		size;

	size = read(fd, buff, BUFF_SIZE);
	*line = (char *)malloc(sizeof(char) * size);
	if (fd < 0)
		return (-1);
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		buff[BUFF_SIZE] = '\0';
		*line = find_newline(buff);
		return (1);
	}
	return (0);
}

int		main(void)
{
	int fd;
	char	**line;

	fd = open("file.txt", O_RDONLY);
	if (get_next_line(fd, line))
		printf("|line = %s|\n", *line);
	return (0);
}
