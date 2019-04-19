/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrkharb <ikrkharb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:48:57 by ikrkharb          #+#    #+#             */
/*   Updated: 2019/04/18 19:51:33 by ikrkharb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

typedef	struct	s_lst
{
	int 	n_bytes;
	char	ptr[50];
	void	*next;
}				t_lst;

t_lst		*get_next_line(const int fd, char **line)
{
	(void)**line;
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	ft_bzero((void *)new->ptr, 50);
	new->n_bytes = read(fd, new->ptr, 32);
	new->next = NULL;
	return (new);
}

int		main(void)
{
	t_lst	*head;
	char	*line;
	int		fd;

	fd = open("file.txt", O_RDONLY);
	head = get_next_line(fd, &line);
	//printf("n_bytes = %d\n", head->n_bytes);
	printf("%s\n", head->ptr);
	return (0);
}
