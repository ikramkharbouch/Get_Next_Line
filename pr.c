/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:29:24 by ikrkharb          #+#    #+#             */
/*   Updated: 2019/04/18 22:33:50 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#define SIZE 1024

int	main(int argc, char *argv[])
{
	int		fd;
	char	buf[SIZE + 1];
	int		n;
	int		i;

	if (argc == 1)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	while ((n = read(fd, buf, SIZE)) != 0)
	{
		printf("n = %d && i = %d\n", n, i); 
		buf[n] = '\0';
		//write(1, buf, n);
		i++;
	}
	return (0);
}
