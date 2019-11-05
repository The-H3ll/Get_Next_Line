/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:39:23 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/05 15:44:22 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"
#include <stdio.h>


int		main(int ac, char **av)
{
	char *line;
	int fd;

	if (ac <=1)
		printf("Put a Text to read\n");
	fd = open(av[1], O_RDONLY);
	/*
	 * Incomment this if u want to read the Whole file
	 *
	 * while (get_next_line(fd, &line) != 0)
	 * {
	 * 		printf("%s\n", line);
	 * 		free(line);
	 * 	}
	 * 	printf("%s", line);
	 */
	get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}
	
