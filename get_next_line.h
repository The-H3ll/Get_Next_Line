/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:15:56 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/02 17:28:58 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE
# define GET_NEXT_LINE

//# define BUFFER_SIZE 	1
# define TRUE 			1
# define FALSE 			0

/* Includes*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prototypes */

int		get_next_line(int fd, char **line);

/*	Linked list */

typedef struct			s_line
{
	char 				*line;
	struct s_line		*next;
}						t_line;

# endif
