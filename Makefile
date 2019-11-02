# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molabhai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 15:06:31 by molabhai          #+#    #+#              #
#    Updated: 2019/10/28 22:36:14 by molabhai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc

FLAGS = -Wall -Wextra -Werror 

HEADER = get_next_line.h

SRC = get_next_line.c main.c

RM = rm -rf

OBJ = $(SRC:.c=.o)

all:
	$(CC) $(FLAGS) -c $(SRC) $(HEADER)

clean:
	$(RM) $(OBJ)

re : clean all

fclean : re clean

.PHONY : all re fclean clean

