/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 00:18:24 by ikrkharb          #+#    #+#             */
/*   Updated: 2019/04/26 15:00:45 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int		main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("input", O_RDONLY);
	while (get_next_line(fd,&line) == 1)
	{
		printf("%d  == %s\n", i, line);
		ft_strdel(&line);
		i++;
	}
	//printf("%s\n", line);
	return (0);
}
