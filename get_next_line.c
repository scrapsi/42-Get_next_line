/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baantoin <baantoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:10:24 by baantoin          #+#    #+#             */
/*   Updated: 2026/11/27 11:51:06 by baantoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	i;
	static int	j;
	static char	*buffer;
	char		*dest;

	if (i == 0)
	{
		buffer = malloc(BUFFER_SIZE);
		if (!buffer)
			return (NULL);
		read(fd, buffer, BUFFER_SIZE);
	}
	while (i < BUFFER_SIZE && buffer[i] && buffer[i] != '\n')
		i++;
	if (i < BUFFER_SIZE && buffer[i] == '\n')
		i++;
	if (buffer[i] == '\0' || i >= BUFFER_SIZE)
		return (NULL);
	dest = malloc(i);
	ft_memcpy(dest, buffer + j, i);
	j = i;
	return (dest);
}
int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test", O_RDONLY);
	while (line = get_next_line(fd))
	{
		if (line == NULL)
			return (0);
		printf("%s", line);
        printf("\n");
	}
}