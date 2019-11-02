/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molabhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:40:09 by molabhai          #+#    #+#             */
/*   Updated: 2019/11/02 17:29:40 by molabhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		word_len(char *str)
{
	int j;

	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == '\n')
			return (j);
		j++;
	}
	return (j);
}


char	*ft_strdup(char *str)
{
	char *s;
	int i;

	if (!(s = (char *)calloc(strlen(str) + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*add_in(char *str, char *ptr)
{
	int i;
	int j;
	char *s;
	char *p;

	p = NULL;
	if (ptr)
		p = ft_strdup(ptr);
	if (!(s = (char *)malloc(sizeof(char) * ((str ? strlen(str) : 0) + (p ? strlen(p) : 0) + 1))))
		return (NULL);	
	i = 0;
	j = 0;
	while (p && p[i] != '\0')
	{
		s[i] = ptr[i];
		i++;
	}
	while (str && str[j] != '\0')
	{
		s[i] = str[j];
		i++;
		j++;
	}
	s[i] = '\0';
	free(ptr);
	free(p);
	return (s);
}


int		search(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

int		get_next_line(int fd, char **line)
{
	char *str;
	static char *ptr;
	char *tmp;
	char *k;

	tmp = NULL;
	line[0] = NULL;
	k = NULL;
	if (!fd)
		return (-1);
	if (!(str = (char *)calloc(BUFFER_SIZE, sizeof(char))))
		return (-1);
	if (ptr)
		tmp = ft_strdup(ptr);
	while (read(fd, str, BUFFER_SIZE) > 0)
	{
		tmp = add_in(str, tmp);
		if (search(tmp) == TRUE)
		{
			ptr = tmp + word_len(tmp) + 1;
			line[0] = ft_strdup(tmp);
			free(str);
			free(tmp);
			return (1);
		}
	}
	if (read(fd, str, BUFFER_SIZE) == 0)
		if(tmp)
			line[0] = ft_strdup(tmp);
	free(tmp);
	free(str);
	return (0);
}
