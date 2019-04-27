/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:20:04 by ikrkharb          #+#    #+#             */
/*   Updated: 2019/04/26 14:27:59 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_is_found(char **line, char *buff, char *pos)
{
	char	*new;
	char	*sub_str;

	if (!(sub_str = ft_strsub(buff, 0, pos - buff)))
		return (0);
	if (!(new = ft_strjoin(*line, sub_str)))
	{
		ft_strdel(&sub_str);
		return (0);
	}
	ft_strdel(line);
	ft_strdel(&sub_str);
	*line = new;
	ft_strcpy(buff, pos + 1);
	return (1);
}

int		ft_not_found(char **line, char *buff, int size)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(*line, buff)))
		return (0);
	ft_strdel(line);
	*line = tmp;
	ft_bzero(buff, size);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE + 1];
	int			size;
	char		*pos;

	if (fd < 0 || read(fd, NULL, 0) == -1)
		return (-1);
	if (!line)
		return (-1);
	*line = buff[0] ? ft_strdup(buff) : ft_strdup("");
	while ((size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[size] = '\0';
		if ((pos = ft_strchr(buff, '\n')))
		{
			if (!ft_is_found(line, buff, pos))
				return (-1);
			return (1);
		}
		else if (!ft_not_found(line, buff, size))
			return (-1);
	}
	ft_strdel(line);
	return (0);
}
