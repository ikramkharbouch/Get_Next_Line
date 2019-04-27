/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:20:04 by ikrkharb          #+#    #+#             */
/*   Updated: 2019/04/26 15:17:44 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_buff_extract(char **line, char *buff)
{
	char	*ads;
	char	*ptr;

	if (buff[0])
	{
		if ((ads = ft_strchr(buff, '\n')))
		{
			*line = (char *)malloc(((ads - buff) + 1)*sizeof(char));
			ptr = ft_memccpy(*line, buff, '\n', ft_strlen(buff));
			*(ptr - 1) = '\0';
			ft_strcpy(buff, ads+1);
		}
		else
		{
			*line = ft_strdup(buff);
		}
	}
	else
	{
		*line = ft_strdup("");
	}
}

int		get_next_line(const int fd, char **line)
{
	static char	buff[4864][BUFF_SIZE + 1];
	int		size;
	char*	ads;

	if (fd < 0 || fd > 4863)
		return (-1);
	printf("buff is '%s' and line is '%s'\n", buff[fd], *line);
	ft_buff_extract(line, buff[fd]);
	printf("buff is '%s' and line is '%s'\n", buff[fd], *line);
	while ((size = read(fd, buff[fd], BUFF_SIZE)) > 0)
	{
		buff[fd][size] = '\0';
		if ((ads = ft_strchr(buff[fd], '\n')))
		{
			*line = ft_strjoin(*line, ft_strsub(buff[fd], 0, ads - buff[fd]));
			ft_strcpy(buff[fd], ads + 1);
			return (1);
		}
		else
		{
			*line = ft_strjoin(*line, buff[fd]);
			ft_bzero(buff[fd], BUFF_SIZE);
		}
	}
	return (0);
}
