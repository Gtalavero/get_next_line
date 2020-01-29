/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaver@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:48:27 by gtalaver          #+#    #+#             */
/*   Updated: 2020/01/29 19:27:52 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** The get_next_line function reads a file and returns the line ending with a
** newline character from a file descriptor. A static variable is used, so that
** whenever get_next_line is called, it remembers the previous function call.
** When get_next_line is first called, we check to see if our static variable
** **s is empty. If it is, we allocate memory for it using our buff string.
** In the loop, we will continue to read more of the line and join them together
** using a temporary string. This temporary string will replace the stored data
** each iteration so that we can keep track of how much is read and delete
** the previous stored data. This is needed because we are only reading so many
** n-bytes at a time decided by our BUFF_SIZE. If we read at each iteration
** without freeing memory, then we would have memory leaks. The loop breaks when
** a newline is encountered. Finally, we call output function to check what
** should be returned.
*/
static char		*ft_saveline(char *auxfd, char **line, int *reader)
{
	int		i;
	char	*temp;

	i = 0;
	while(auxfd[i] && auxfd[i] != '\n')
		i++;
	if(auxfd[i] == '\n')
	{
		*line = ft_substr(auxfd, 0, i);
		temp = ft_strdup(auxfd + i + 1);
		free(auxfd);
		auxfd = temp;
		if(auxfd[0] == '\0')
		{
			free(auxfd);
			auxfd = NULL;
		}
		*reader = 1;
	}
	else
	{
		*line = ft_strjoin(*line, ft_substr(auxfd, 0, i));
		free(auxfd);
		auxfd = NULL;
		*reader = 0;
	}
	return (auxfd);
}

int get_next_line(int fd, char **line)
{
	static char	*auxfd[4096];
	char		*buff;
	int			reader;

	if(fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if(!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while((reader = read(fd, buff, BUFFER_SIZE)) > 0 )
	{
		buff[reader] = '\0';
		if(auxfd[fd] == NULL)
			auxfd[fd] = ft_strdup(buff);
		else
			auxfd[fd] = ft_strjoin(auxfd[fd], buff);
		if (ft_strchr(auxfd[fd], '\n'))
			break;
	}
	free(buff);
	if(reader < 0)
	{
		return (-1);
		*line = ft_strdup("");
	}
	if(reader == 0 && auxfd[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	auxfd[fd] = ft_saveline(auxfd[fd], line, &reader);
	return(reader);
}
//Tema errores