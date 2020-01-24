/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaver@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:48:27 by gtalaver          #+#    #+#             */
/*   Updated: 2020/01/24 20:30:03 by gtalaver         ###   ########.fr       */
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

int get_next_line(int fd, char **line)
{
	static char	*auxfd[4096];
	char		*buff;
	int			reader;
	
	if(fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if(!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if((reader = read(fd, buff, BUFFER_SIZE)) > 0)
	{
			buff[reader] = '\0';
			auxfd[fd] = ft_strdup(buff); // Si no hay nada en auxfd, lo llenamos con buff
	}
	while((reader = read(fd, buff, BUFFER_SIZE)) > 0 &&
							!(ft_strchr(auxfd[fd], '\n')))	//¿Quitar BUFFER_SIZE? Guarda en buff. read: Nº carácteres, fallo lectura = -1, EOF = 0, 
	{
		buff[reader] = '\0';  //¿quitarlo?
		auxfd[fd] = ft_strjoin(auxfd[fd], buff);	// Si auxfd tenía contenido, lo concatenamos con buff
	}
	free(buff);
	if(reader < 0)
		return (-1);
	if(reader == 0)
	{
		*line = ft_strdup("");
		return (0);
	}
	//PENDIENTE retornamos len (0 o 1) en funcion de lo que retorne ft_line, 1 si hemos leido una linea, 0 si hemos terminado de leer.
	return(0);
}
