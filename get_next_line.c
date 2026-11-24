/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baantoin <baantoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:10:24 by baantoin          #+#    #+#             */
/*   Updated: 2026/11/24 14:40:56 by baantoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		file_size;
	char	*buffer;

	file_size = read(fd, buffer, 1000);
    return(0);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
    int fd;
	printf("fd : {%d}\n", fd = open("test", 1));
    get_next_line(fd);
    return(0);
}
