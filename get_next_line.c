/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baantoin <baantoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:10:24 by baantoin          #+#    #+#             */
/*   Updated: 2026/11/25 09:23:10 by baantoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd)
{
	static int	i = 0;
	static int	file;
	static char	*buffer;

	if (i == 0)
	{
		buffer = malloc(BUFFER_SIZE);
		if (!buffer)
			return (-1);
		file = read(fd, buffer, BUFFER_SIZE);
		if (file <= 0)
			return (-1);
	}
	while (i < file && buffer[i] != '\n')
	{
		write(1, &buffer[i], 1);
		i++;
	}
	if (i < file && buffer[i] == '\n')
		i++;
	printf("i : {%d}\n", i);
	return (0);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	return (0);
}
