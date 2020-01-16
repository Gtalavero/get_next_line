/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaver@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:48:27 by gtalaver          #+#    #+#             */
/*   Updated: 2020/01/15 20:31:29 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
/*
** 	static char	sdsize[4096];
*/
	char	*buff;

	*line = "hello";
	if(!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	read(fd, buff, BUFFER_SIZE);
	ft_putstr(buff);
	return(0);
}
