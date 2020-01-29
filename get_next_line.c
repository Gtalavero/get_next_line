/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaver@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:48:27 by gtalaver          #+#    #+#             */
/*   Updated: 2020/01/29 17:55:23 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Recibiremos un auxfd que podria continuar despues del \n, por lo que tendremos
// que limpiarlo y almacenar en line hasta el \n.
static char		*ft_saveline(char *auxfd, char **line)
{
	// Almacenar en line el contenido de auxfd hasta el salto de linea.
	// Limpiar auxfd
	int		i;
	char	*temp; //tamanio?

	i = 0;
	// Contamos los caracteres de auxfd hasta el \n.
	while(auxfd[i] && auxfd[i] != '\n')
		i++;
	if(auxfd[i] == '\n')
	{
		*line = ft_substr(auxfd, 0, i);
		temp = ft_strdup(auxfd + i + 1);
		free(auxfd);
		auxfd = temp;
		// free(temp);
	}
	else
	{
		*line = ft_strjoin(*line, ft_substr(auxfd, 0, i));
	}

	return (auxfd);
}
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
		return (-1);
	if(reader == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	auxfd[fd] = ft_saveline(auxfd[fd], line);
	return(reader);
}
